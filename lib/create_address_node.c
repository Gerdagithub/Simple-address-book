#include "linkedList.h"
#include "/usr/local/src/additional.h"

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