#include "linkedList.h"
#include "/usr/local/src/additional.h"

struct Person *find_address_by_keyword(struct Person *list, char *keyword)
{
    struct Person *temp_list = NULL;
    struct Person *node = NULL;
    struct Person *temp = list;
    int found = 0;
    while(temp != NULL) {
        if(strcmp(temp->name, keyword) == 0) {
            found = 1;
        } else if(strcmp(temp->surname, keyword) == 0) {
            found = 1;
        } else if(strcmp(temp->email, keyword) == 0) {
            found = 1;
        } else if(strcmp(temp->number, keyword) == 0) {
            found = 1;
        }
        if(found) {
            found = 0;
            node = copy_node(temp);
            add_to_the_end_of_the_list(&temp_list, node);
        }
        temp = temp->next;
    }
    return temp_list;
}
