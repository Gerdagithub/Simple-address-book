CC:=gcc
BIN:=address_book
LDLIBS:=-L/usr/local/lib -Wl,-rpath=/usr/local/lib -llinkedList
SRCDIR:=/usr/local/src/
CFLAGS:=-Wall

all: make_src make_lib $(BIN)

$(BIN): $(SRCDIR)main.o $(SRCDIR)additional.o
        $(CC) $(LDLIBS) $(CFLAGS) -o $@ $(SRCDIR)main.o $(SRCDIR)additional.o -llinkedList

make_src:
        make -C /usr/local/src

make_lib:
        make -C /usr/local/lib

.PHONY: all make_src make_lib valgrind clean

valgrind: $(BIN)
        valgrind --leak-check=full --show-leak-kinds=all ./$<

clean:
        $(RM) $(BIN)
        make -C /usr/local/src clean
        make -C /usr/local/lib clean