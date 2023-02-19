#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "linkedList.h"
#define DELIMETER ","

void load_addresses(FILE *file, struct Person **list)
{
    char line[128];

    while (fgets(line, sizeof(line), file)) {
        struct Person *person = NULL;
        if (strcmp(line, "\n") == 0)
            continue;

        person = create_address_node(line);
        if (person != NULL)
            add_to_the_end_of_the_list(list, person);
    }
}

struct Person *create_address_node(char *address_line)
{
    struct Person *person = NULL;
    char *name;
    char *surname;
    char *email;
    char *number;

    name = strtok(address_line, DELIMETER);
    surname = strtok(NULL, DELIMETER);
    email = strtok(NULL, DELIMETER);
    number = strtok(NULL, DELIMETER);

    if (strlen(number) - 1 != 0)
        number[strlen(number) - 1] = '\0';

    person = create_node(name, surname, email, number);

    return person;
}

struct Person *create_node(char *name, char *surname, char *email, char *number)
{
    struct Person *person = NULL;
    person = (struct Person*)malloc(sizeof(struct Person));
    if (person == NULL) {
        return NULL;
    }
    strcpy(person->name, name);
    strcpy(person->surname, surname);
    strcpy(person->email, email);
    strcpy(person->number, number);

    person->next = NULL;
    return person;
}

void print_list(struct Person *list)
{
    int entry = 1;

    if (list != NULL) {
        struct Person *temp = list;
        while (temp != NULL) {
            printf("Entry %d -> Name - %s --- Surname - %s --- Email - %s --- Number - %s\n",
                    entry, temp->name, temp->surname, temp->email, temp->number);

            temp = temp->next;
            entry++;
        }
        printf("\n");
    }
    else printf("The address book is empty.\n");
}

void add_to_the_end_of_the_list(struct Person **list, struct Person *person)
{
    struct Person *temp = *list;
    if (temp == NULL) {
        *list = person;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = person;
}

void insert_to_the_list(struct Person **list, struct Person *person, int position,
                        bool *insertedSuccessfully)
{
    struct Person *curr = *list;

    if (position == 1) {
        person->next = *list;
        *list = person;

        struct Person *temp = *list;
        while (temp != NULL) {
            temp = temp->next;
        }

        *insertedSuccessfully = true;
    }else if(position > 1){
        for (int i = 1; i <= position; i++) {

            if (curr == NULL) {
                break;
            }
            else if (i == position - 1) {
                *insertedSuccessfully = true;
                person->next = curr->next;
                curr->next = person;
            }
            curr = curr->next;
        }
    }
}

struct Person *find_address(struct Person **list, int index)
{
    struct Person *curr = *list;

    if (index == 1)
        return curr;
    else if (index > 1){
        for (int i = 0; i < index - 1; i++) {
            if (curr == NULL) {
                return NULL;
            }
            curr = curr->next;
        }
        return curr;
    }

    return NULL;
}

// Function that finds address by keyword. The keyword can be name, surname, email or phone number.
struct Person *found_address_by_keyword(struct Person *list, char *data, char *keyword)
{
    struct Person *temp = list;

    while (temp != NULL) {
        if (strcmp(keyword, "name") == 0 && strcmp(temp->name, data) == 0)
            return temp;

        if (strcmp(keyword, "surname") == 0 && strcmp(temp->surname, data) == 0)
            return temp;

        if (strcmp(keyword, "email") == 0 && strcmp(temp->email, data) == 0)
            return temp;

        if (strcmp(keyword, "number") == 0 && strcmp(temp->number, data) == 0)
            return temp;

        temp = temp->next;
    }

    return NULL;
}

void delete_address(struct Person **list, int position, bool *deletedSuccessfully)
{
    struct Person *temp = *list;

    if (position == 1) {
        *list = (*list)->next;
        *deletedSuccessfully = true;
    }else if (position > 1){
        for (int i = 0; i < position - 2; i++) {
            if (temp == NULL) {
                return;
            }
            temp = temp->next;
        }
        struct Person *temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
        *deletedSuccessfully = true;
    }
}

int size_of_the_book(struct Person *list)
{
    struct Person *temp = list;
    int size = 0;
    if (temp != NULL){
        while (temp != NULL) {
            temp = temp->next;
            size++;
        }
    }

    return size;
}

void delete_list(struct Person **list)
{
    struct Person *to_delete = *list;
    struct Person *next;

    while (to_delete != NULL)
    {
        next = to_delete->next;
        free(to_delete);
        to_delete = next;
    }

    *list = NULL;
}