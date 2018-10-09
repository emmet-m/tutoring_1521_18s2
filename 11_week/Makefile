CC=gcc
CFLAGS=-Wall -Werror -g

SRCS=$(wildcard *.c)
PROGS=$(patsubst %.c,%,$(SRCS))
all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) -f $(PROGS)
