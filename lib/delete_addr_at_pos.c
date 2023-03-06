#include "linkedList.h"
#include "/usr/local/src/additional.h"

int delete_addr_at_pos(struct Person **list, int position)
{
    struct Person *prev = *list;
    struct Person *temp = *list;
    int i = 1;
    if(*list == NULL) {
        return 1;
    }
    while(temp != NULL) {
        if(position == i) {
            prev->next = temp->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
        i++;
    }
    return 0;
}