SRC:=$(wildcard *.c)
OBJS:=$(SRC:.c=.o)

all: program

program: $(OBJS)
        $(CC) -o $@ $^

.PHONY: clean

clean:
        $(RM) $(OBJS) program