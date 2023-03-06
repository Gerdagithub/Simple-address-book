CC:=gcc
BIN:=address_book
LDLIBS:=-L/usr/local/lib -Wl,-rpath=/usr/local/lib -llinkedList
SRCDIR:=/usr/local/src/
CFLAGS:=-Wall

all: $(BIN)

$(BIN): $(SRCDIR)main.o $(SRCDIR)additional.o
        $(CC) $(LDLIBS) $(CFLAGS) -o $@ $(SRCDIR)main.o $(SRCDIR)additional.o -llinkedList

.PHONY: all valgrind clean

valgrind: $(BIN)
        valgrind --leak-check=full --show-leak-kinds=all ./$<

clean:
        $(RM) $(BIN)