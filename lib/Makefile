LIB:=liblinkedList.so
SRCS:=$(wildcard *.c)
OBJS:=$(SRCS:.c=.o)
CFLAGS:=-Wall
LDFLAGS:=-shared

.PHONY: all clean

all: $(LIB)

$(LIB): $(OBJS)
	$(CC) $(CFLAGS) -fpic -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -fpic $(CFLAGS) -c -o $@ $^ $(LDFLAGS)

clean:
	$(RM) $(OBJS) $(LIB)
