CC=gcc
SRCS=create_node.c create_address_node.c print_list.c add_to_the_end_of_the_list.c insert_to_the_list.c find_address.c find_address_by_keyword.c copy_node.c delete_addr_at_pos.c size_of_the_book.c delete_list.c
OBJS=$(SRCS:.c=.o)
CFLAGS=-fpic -Wall

all: liblinkedList.so

liblinkedList.so: $(OBJS)
        $(CC) -shared $(OBJS) -o $@

$(OBJS): $(SRCS)
        $(CC) $(CFLAGS) -c $(SRCS)

clean:
        $(RM) $(OBJS) liblinkedList.so