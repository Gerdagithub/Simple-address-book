#include "linkedList.h"
#include "/usr/local/src/additional.h"

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