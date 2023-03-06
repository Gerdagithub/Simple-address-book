#include "linkedList.h"
#include "/usr/local/src/additional.h"

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