#include "linkedList.h"
#include "/usr/local/src/additional.h"

struct Person *copy_node(struct Person *src)
{
    struct Person *copy = NULL;
    copy = (struct Person *) malloc(sizeof(struct Person));
    if (copy == NULL) {
        return NULL;
    }
    strcpy(copy->name, src->name);
    strcpy(copy->surname, src->surname);
    strcpy(copy->email, src->email);
    strcpy(copy->number, src->number);
    copy->next = NULL;
    return copy;
}