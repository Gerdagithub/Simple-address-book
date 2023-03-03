SRC:=$(wildcard *.c)

all: program

program: $(SRC)
        $(CC) -o $@ $^

.PHONY: clean

clean:
        $(RM) program