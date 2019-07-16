# A quick and dirty makefile for compiling hw2
CFLAGS=-g -Wall -std=c99 -lm

TESTS=all gdb2

all:
	gcc $(CFLAGS) array_tester.c arraysort.c get_max_ARM.s get_min_ARM.s createlist_ARM.s insert_ARM.s pop_min_ARM.s print_ARM.s remove_val_ARM.s search_ARM.s -o pa2

gdb2:
	gcc -g -o gdb2 gdb2.c

clean:
	rm -f $(TESTS)