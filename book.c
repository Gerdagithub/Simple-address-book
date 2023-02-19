#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <pwd.h>
#include <unistd.h>

#include "linkedList.h"

struct Person *newPerson();
char Choice();

int main(void)
{
    struct Person *list = NULL;

    uid_t uid = geteuid();
    struct passwd *pw = getpwuid(uid);
    char path[30];
    strcpy(path, pw->pw_dir);
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
    char *keyword = NULL;
    keyword = (char*)malloc(sizeof(char*) * 8);
    char *data = NULL;
    data = (char*)malloc(sizeof(char*) * 31);
    char garb[50];

    while (input != '9') {
        if (input == '1') {
            print_list(list);
            input = Choice();
            continue;
        }
        if (input == '2') {
            success = false;
            struct Person *enteredPerson = NULL;
            enteredPerson = (struct Person*)malloc(sizeof(struct Person*));
            if (enteredPerson != NULL) {
                enteredPerson = newPerson();
                if (enteredPerson != NULL){
                    add_to_the_end_of_the_list(&list, enteredPerson);
                    printf("Address successfully was added to the list\n");
                    success = true;
                }
            }
            if (!success)
                printf("The request could not be fulfilled\n");

            input = Choice();
            continue;
        }
        if (input == '3') {
            success = false;
            struct Person* enteredPerson = NULL;
            enteredPerson = (struct Person*)malloc(sizeof(struct Person*));
            if (enteredPerson != NULL) {
                enteredPerson = newPerson();
                printf("Enter position: ");
                scanf("%d", &position);
                fgets(garb, sizeof(garb), stdin);
                printf("\n");
                insert_to_the_list(&list, enteredPerson, position, &success);
                if (success){
                    printf("Address successfully was inserted to %dth position in the list\n", position);
                }
            }
            if (!success)
                printf("The request could not be fulfilled\n");
            position = -1;

            input = Choice();
            continue;
        }
        if (input == '4') {
            success = false;
            struct Person *foundPerson = NULL;
            foundPerson = (struct Person*)malloc(sizeof(struct Person*));
            if (!(keyword == NULL || data == NULL || foundPerson == NULL)){
                printf("Enter position: ");
                scanf("%d", &position);
                fgets(garb, sizeof(garb), stdin);
                foundPerson = find_address(&list, position);
                if (foundPerson != NULL) {
                      printf("\nAddress in %dth position:\n-> Name - %s --- Surname - %s --- Email - %s --- Number - %s\n",
                              position, foundPerson->name, foundPerson->surname,
                              foundPerson->email, foundPerson->number);

                    success = true;
                }
                position = -1;
            }
            if (!success)
                printf("The request could not be fulfilled\n");

            input = Choice();
                continue;

        }

        if (input == '5') {
            success = false;
            struct Person *foundPerson = NULL;
            foundPerson = (struct Person*)malloc(sizeof(struct Person*));
            if (keyword == NULL || data == NULL || foundPerson == NULL) {
                printf("The request could not be fulfilled\n");
            }
            else {
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
                    foundPerson = found_address_by_keyword(list, data, keyword);
                    if (foundPerson != NULL) {
                        printf("\nFound address:\n-> Name - %s --- Surname - %s --- Email - %s --- Number - %s\n",
                              foundPerson->name, foundPerson->surname,
                              foundPerson->email, foundPerson->number);

                        success = true;
                    }
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
            free(keyword);
            free(data);
            exit(0);
        }
    }

    return 0;
}

char Choice()
{
    char input;
    char symb = '9';
    char garb[50];

beginning:
    printf("\nEnter your choice: ");
    scanf("%c", &input);
    fgets(garb, sizeof(garb), stdin);
    printf("\n");

    if (input < '1' || input > '9') {
        printf("Only numbers 1 to 8 can be chosen.\n");
        printf("If you want to try again type 'Y', if no, type 'N':\n");
        scanf("%c", &symb);
        fgets(garb, sizeof(garb), stdin);
        if (symb == 'Y') {
            goto beginning;
        }else {
            return '9';
        }
    }

    return input;
}

struct Person *newPerson()
{
    struct Person *newPerson = NULL;
    newPerson = (struct Person*)malloc(sizeof(struct Person*)*100);
    char garb[50];

    if (newPerson != NULL) {
        printf("Enter name: ");
        scanf("%30[^\n]", newPerson->name);
        fgets(garb, sizeof(garb), stdin);

        printf("Enter surname: ");
        scanf("%30[^\n]", newPerson->surname);
        fgets(garb, sizeof(garb), stdin);

        printf("Enter email: ");
        scanf("%30[^\n]", newPerson->email);
        fgets(garb, sizeof(garb), stdin);

        printf("Enter phone number: ");
        scanf("%30[^\n]", newPerson->number);
        fgets(garb, sizeof(garb), stdin);

        newPerson->next = NULL;
    } else return NULL;

    return newPerson;
}