#include "linkedList.h"
#include "/usr/local/src/additional.h"

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