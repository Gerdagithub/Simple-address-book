#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "linkedList.h"
#include "additional.h"

int main(void)
{
    struct Person *list = NULL;

    char path[30];
    strcpy(path, getenv("HOME"));
    strcat(path, "/addresses.csv");
    FILE *address_file = fopen(path, "r");

    if (address_file != NULL) {
        load_addresses(address_file, &list);
    }

    printf("1: Print address book\n");
    printf("2: Add to address book\n");
    printf("3: Add address at position\n");
    printf("4: Find address by position\n");
    printf("5: Find address by keyword\n");
    printf("6: Delete address at position\n");
    printf("7: Get address book size\n");
    printf("8: Delete address book\n");
    printf("9: Exit\n");

    char input = Choice();
    int position;
    bool success;
    char keyword[8];
    char data[30];
    char garb[50];
    struct Person *person;

    while (input != '9') {
        if (input == '1') {
            print_list(list);
            input = Choice();
            continue;
        }
        if (input == '2') {
            success = false;
            person = newPerson();
            if (person != NULL){
                add_to_the_end_of_the_list(&list, person);
                printf("Address successfully was added to the list\n");
                success = true;
            }
            if (!success)
                printf("The request could not be fulfilled\n");

            input = Choice();
            continue;
        }
        if (input == '3') {
            success = false;
            person = newPerson();
            printf("Enter position: ");
            scanf("%d", &position);
            fgets(garb, sizeof(garb), stdin);
            printf("\n");
            insert_to_the_list(&list, person, position, &success);
            if (success){
                printf("Address successfully was inserted to %dth position in the list\n", position);
            }
            if (!success)
                printf("The request could not be fulfilled\n");
            position = -1;

            input = Choice();
            continue;
        }
        if (input == '4') {
            success = false;
            printf("Enter position: ");
            scanf("%d", &position);
            fgets(garb, sizeof(garb), stdin);
            person = find_address(&list, position);
            if (person != NULL) {
                printf("\nAddress in %dth position:\n-> Name - %s --- Surname - %s --- Email - %s --- Number - %s\n",
                        position, person->name, person->surname,
                        person->email, person->number);
                        
                    success = true;
            }
            //position = -1;
            if (!success)
                printf("The request could not be fulfilled\n");

            input = Choice();
                continue;
        }

        if (input == '5') {
            success = false;
            printf("Enter a keyword (name, surname, email or number): ");
            scanf("%s", keyword);
            printf("\n");
            fgets(garb, sizeof(garb), stdin);
            if (strcmp(keyword, "name") == 0 ||
                strcmp(keyword, "surname") == 0 ||
                strcmp(keyword, "email") == 0 ||
                strcmp(keyword, "number") == 0) {

                printf("Enter %s: ", keyword);
                scanf("%s", data);
                fgets(garb, sizeof(garb), stdin);
                person = found_address_by_keyword(list, data, keyword);
                if (person != NULL) {
                    printf("\nFound address:\n-> Name - %s --- Surname - %s --- Email - %s --- Number - %s\n",
                          person->name, person->surname,
                          person->email, person->number);

                    success = true;
                }
            }
            if (!success)
                printf("The request could not be fulfilled\n");

            input = Choice();
            continue;
        }
        if (input == '6') {
            success = false;
            printf("Enter position: ");
            scanf("%d", &position);
            fgets(garb, sizeof(garb), stdin);
            printf("\n");
            delete_address(&list, position, &success);
            if (success)
                printf("Address in %dth position was successfully deleted.\n",
                       position);
            else printf("The request could not be fulfilled\n");
            position = -1;

            input = Choice();
            continue;
        }
        if (input == '7') {
            printf("Size of the address book: %d\n", size_of_the_book(list));
            input = Choice();
            continue;
        }
        if (input == '8') {
            delete_list(&list);
            printf("Address book was successfully deleted.\n");
            input = Choice();
            continue;
        }
        if (input == '9') {
            exit(0);
        }
    }

    return 0;
}