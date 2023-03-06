#include "linkedList.h"
#include "/usr/local/src/additional.h"

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
