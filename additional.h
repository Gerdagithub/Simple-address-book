#define DELIMETER ","

enum actions{
    printList = 1,
    addToEnd,
    addAtPosition,
    findByPosition,
    findByKeyword,
    deleteAtPosition,
    getSizeOfList,
    deleteList,
    exitProgram
};

void Print_usage();
int Choice();
void parse_user_input(char *name, char *surname, char *email, char *number);
int get_user_pos();
char *get_user_keyword();
void load_addresses(FILE *file, struct Person **list);
void add_address(struct Person **list);
void Add_address_at_position(struct Person **list);
void find_by_position(struct Person **list);
void find_by_keyword(struct Person *list);
void delete_at_position(struct Person **list);