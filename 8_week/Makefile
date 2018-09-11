CC=gcc
CFLAGS=-Wall -Werror

SRCS=$(wildcard *.c)
PROGS=$(patsubst %.c,%,$(SRCS))
all: $(PROGS)

%: %.c
	$(CC) $(FLAGS) -o $@ $<

clean:
	$(RM) -f $(PROGS)
