#include "linkedList.h"
#include "/usr/local/src/additional.h"

void print_list(struct Person *list)
{
    int entry = 1;

    if (list == NULL)
        printf("The address book is empty.\n");

    struct Person *temp = list;
    while (temp != NULL) {
        printf("Entry %d -> Name - %s --- Surname - %s --- Email - %s --- Number - %s\n",
                entry, temp->name, temp->surname, temp->email, temp->number);

        temp = temp->next;
        entry++;
    }
    printf("\n");
}