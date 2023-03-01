/*#include <stdio.h>
#include <string.h>

#include "linkedList.h"
#include "additional.h"*/
#include "main.h"

static int run_loop = 1;

int main(run_loop)
{
    struct Person *list = NULL;
    enum actions choice;

    char path[30];
    strcpy(path, getenv("HOME"));
    strcat(path, "/addresses.csv");
    FILE *address_file = fopen(path, "r");

    if (address_file != NULL) {
        load_addresses(address_file, &list);
    }

    Print_usage();

    while (run_loop) {
        switch (choice = Choice()){
        case printList:
            print_list(list);
            break;
        case addToEnd:
            add_address(&list);
            break;
        case addAtPosition:
            Add_address_at_position(&list);
            break;
        case findByPosition:
            find_by_position(&list);
            break;
        case findByKeyword:
            find_by_keyword(list);
            break;
        case deleteAtPosition:
            delete_at_position(&list);
            break;
        case getSizeOfList:
            printf("Size of the address book: %d\n", size_of_the_book(list));
            break;
        case deleteList:
            delete_list(&list);
            printf("Address book was successfully deleted.\n");
            break;
        case exitProgram:
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