CC = gcc
CFLAGS = -std=c99 -Wall -Wextra

SRCS = $(wildcard hw*/*.c)
BINS = $(patsubst %.c,bin/%,$(notdir $(SRCS)))

vpath %.c $(sort $(dir $(SRCS)))

all: $(BINS)

bin/%: %.c | bin
	$(CC) $(CFLAGS) $< -o $@

bin:
	mkdir -p bin

clean:
	rm -rf bin

.PHONY: all clean
