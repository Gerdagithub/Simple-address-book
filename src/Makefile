BIN:=address_book
SRC:=$(wildcard *.c)
OBJ:=$(SRC:.c=.o)
CFLAGS:=-Wall
CPPFLAGS:=-I../lib
LDFLAGS:=-L../lib
LDLIBS:=-llinkedList

.PHONY: all clean

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)

%.o:%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $^

clean:
	$(RM) $(OBJ) $(BIN)
