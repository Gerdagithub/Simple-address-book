#include <stdlib.h>

struct Person {
    char name[30];
    char surname[30];
    char email[30];
    char number[30];
    struct Person *next;
};

void load_addresses(FILE *file, struct Person **list);
struct Person *newPerson();
struct Person *create_node(char *name, char *surname, char *email, char *number);
struct Person *create_address_node(char *address_line);
void print_list(struct Person *list);
void add_to_the_end_of_the_list(struct Person **list, struct Person *person);
void insert_to_the_list(struct Person **list, struct Person *person, int position, bool *insertedSuccessfully);
struct Person *find_address(struct Person **list, int index);
struct Person *found_address_by_keyword(struct Person *list, char data[], char keyword[]);
void delete_address(struct Person **list, int position, bool *deletedSuccessfully);
int size_of_the_book(struct Person *list);
void delete_list(struct Person **list);