CC:=gcc
BIN:=address_book
LDLIBS:=-L/usr/local/lib -Wl,-rpath=/usr/local/lib -llinkedList
SRCDIR:=/usr/local/src/
CFLAGS:=-Wall

all: $(BIN)

$(BIN):
        $(CC) $(LDLIBS) $(CFLAGS) -o $@ $(SRCDIR)main.c $(SRCDIR)additional.c -llinkedList

.PHONY: all valgrind clean

valgrind: $(BIN)
        valgrind ./$<

clean:
        $(RM) $(BIN)
~                    