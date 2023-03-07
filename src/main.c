#include <stdio.h>
#include <string.h>
#include <signal.h>

#include <linkedList.h>
#include "additional.h"

static int run_loop = 1;

static void signal_handler(int signo)
{
	printf("\nCTRL+C was pressed. Stopping program\n");
	run_loop = 0;
}

int main(void)
{
	struct Person *list = NULL;
	enum actions choice;

	struct sigaction sa;
	memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_handler = signal_handler;
	sa.sa_flags   = 0;

	sigaction(SIGINT, &sa, NULL);

	char path[256];
	strcpy(path, getenv("HOME"));
	strcat(path, "/addresses.csv");
	FILE *address_file = fopen(path, "r");

	if (address_file != NULL) {
		load_addresses(address_file, &list);
	}

	fclose(address_file);

	Print_usage();

	while (run_loop) {
		switch (choice = Choice()) {
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