#include <stdio.h>
#include <string.h>
//#include <stdbool.h>

#include "linkedList.h"
#include "additional.h"

static int run_loop = 1;

int main(run_loop)
{
    struct Person *list = NULL;

    char path[30];
    strcpy(path, getenv("HOME"));
    strcat(path, "/addresses.csv");
    FILE *address_file = fopen(path, "r");

    if (address_file != NULL) {
        load_addresses(address_file, &list);
    }

    Print_usage();

    char input = Choice();
    int position;

    while (run_loop) {
        switch (Choice()){
        case 1:
            print_list(list);
            break;
        case 2:
            add_address(&list);
            break;
        case 3:
            Add_address_at_position(&list);
            break;
        case 4:
            find_by_position(&list);
            break;
        case 5:
            find_by_keyword(list);
            break;
        case 6:
            delete_at_position(&list);
            break;
        case 7:
            printf("Size of the address book: %d\n", size_of_the_book(list));
            break;
        case 8:
            delete_list(&list);
            printf("Address book was successfully deleted.\n");
            break;
        case 9:
            run_loop = 0;
            break;
        default:
            printf("Your selected option doesn't exist\n");
            break;
        }
    }

    delete_list(&list);
    return 0;
}