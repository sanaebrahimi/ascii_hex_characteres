CC := gcc
CFLAGS := -Wall -lm 
SRCS := $(wildcard *.c)
OBJS := $(patsubst %.c,%.o,$(SRCS))

all: $(OBJS)

%.o: %.c
	-$(CC) $(CFLAGS) $< -o $@
clean:
	rm *.o
