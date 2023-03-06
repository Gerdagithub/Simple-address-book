#include "linkedList.h"
#include "/usr/local/src/additional.h"

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
