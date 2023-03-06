#include "linkedList.h"
#include "/usr/local/src/additional.h"

int insert_to_the_list(struct Person **list, struct Person *person, int position)
{
    struct Person *temp = *list;
    int i = 1;
    if(temp == NULL) {
        *list = person;
        return 2; 
    }

    if(position == 1) {
        person->next = temp;
        *list = person;
        return 0;
    }

    while(temp != NULL) {
        if(temp->next == NULL) {
            temp->next = person;
            return 3;
        } else if((position - 1) == i) {
            person->next = temp->next;
            temp->next = person;
            break;
        }
        temp = temp->next;
        i++;
    }
    return 0;
}
