#include "/usr/local/lib/linkedList.h"
#include "additional.h"

void Print_usage()
{
    printf("1: Print address book\n");
    printf("2: Add to address book\n");
    printf("3: Add address at position\n");
    printf("4: Find address by position\n");
    printf("5: Find address by keyword\n");
    printf("6: Delete address at position\n");
    printf("7: Get address book size\n");
    printf("8: Delete address book\n");
    printf("9: Exit\n\n");
}

int Choice()
{
    int input;
    printf("Enter your choice: ");
    scanf("%d", &input);
    while (getchar() != '\n' && input != EOF);

    return input;
}

void parse_user_input(char *name, char *surname, char *email, char *number)
{
    printf("\nEnter First name: ");
    fscanf(stdin, "%29[^\n]", name);
    while (getchar() != '\n' && name != NULL);

    printf("Enter Last name: ");
    fscanf(stdin, "%29[^\n]", surname);
    while (getchar() != '\n' && surname != NULL);

    printf("Enter email: ");
    fscanf(stdin, "%49[^\n]", email);
    while (getchar() != '\n' && email != NULL);

    printf("Enter number: ");
    fscanf(stdin, "%24[^\n]", number);
    while (getchar() != '\n' && number != NULL);
}

int get_user_pos()
{
    int position;
    printf("Enter position: ");
    scanf("%d", &position);
    while (getchar() != '\n' && position != EOF);
    return position;
}

char *get_user_keyword()
{
    char *keyword = (char*) malloc(sizeof(char) * 50);
    printf("Enter search keyword: ");
    fscanf(stdin, "%49[^\n]", keyword);
    while (getchar() != '\n' && keyword != NULL);
    return keyword;
}

void load_addresses(FILE *file, struct Person **list)
{
    char line[132];

    while (fgets(line, sizeof(line), file)) {
        struct Person *person = NULL;
        if (strcmp(line, "\n") == 0)
            continue;

        person = create_address_node(line);
        if (person != NULL)
            add_to_the_end_of_the_list(list, person);
    }
}

void add_address(struct Person **list)
{
    struct Person *address = NULL;
    char name[30], surname[30], number[25], email[50];

    parse_user_input(name, surname, email, number);
    address = create_node(name, surname, email, number);
    if (address == NULL) {
        printf("Unable to create new address\n\n");
        return;
    }
    add_to_the_end_of_the_list(list, address);
    printf("Address successfully was added to the list\n\n");
}

void Add_address_at_position(struct Person **list)
{
    int position;
    int rc;
    struct Person *address = NULL;
    char name[30], surname[30], number[25], email[50];

    position = get_user_pos();
    if (position <= 0) {
        printf("Invalid position\n\n");
        return;
    }
    parse_user_input(name, surname, email, number);
    address = create_node(name, surname, email, number);
    if (address == NULL) {
        printf("Unable to create new address\n");
        return;
    }
    rc = insert_to_the_list(list, address, position);
    switch (rc) {
        case 0:
            printf("Address added at position -> %d\n\n", position);
            break;
        case 2:
            printf("List was empty. Address added to the top\n\n");
            break;
        case 3:
            printf("Address was added to the end of the list. Too few entries in the list\n\n");
            break;
        default:
            break;
    }
}

void find_by_position(struct Person **list)
{
    int position = get_user_pos();
    struct Person *person = find_address(list, position);

    if (person != NULL)
        printf("\nAddress in %dth position:\n-> Name - %s --- Surname - %s --- Email - %s --- Number - %s\n",
                position, person->name, person->surname,
                person->email, person->number);

    else printf("No address was found by the position %d\n", position);
}

void find_by_keyword(struct Person *list)
{
    char *keyword;
    struct Person *temp_list = NULL;
    keyword = get_user_keyword();
    temp_list = find_address_by_keyword(list, keyword);
    if (temp_list != NULL) {
        print_list(temp_list);
    } else {
        printf("No address was found by the keyword - %s\n\n", keyword);
    }
    if (keyword != NULL) {
        free(keyword);
    }
    delete_list(&temp_list);
}

void delete_at_position(struct Person **list)
{
    int position;
    position = get_user_pos();
    if(position < 1 || position > size_of_the_book(*list)) {
        printf("Invalid position\n\n");
        return;
    }
    delete_addr_at_pos(list, position);
}