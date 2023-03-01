#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Person {
    char name[30];
    char surname[30];
    char email[50];
    char number[25];
    struct Person *next;
};

struct Person *create_node(char *name, char *surname, char *email, char *number);
struct Person *create_address_node(char *address_line);
void print_list(struct Person *list);
void add_to_the_end_of_the_list(struct Person **list, struct Person *person);
int insert_to_the_list(struct Person **list, struct Person *person, int position);
struct Person *find_address(struct Person **list, int index);
struct Person *find_address_by_keyword(struct Person *list, char *keyword);
static struct Person *copy_node(struct Person *src);
int delete_addr_at_pos(struct Person **list, int position);
int size_of_the_book(struct Person *list);
void delete_list(struct Person **list);