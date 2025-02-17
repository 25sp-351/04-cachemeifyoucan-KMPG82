# all: main

# OBJS = main.o helpers.o error_handling.o rod_cutting.o cache.o
# CC = clang
# CFLAGS = -g -Wall

# main: $(OBJS)
# 	clang -o main $(CFLAGS) $(OBJS)

# main.o: main.c helpers.h error_handling.h rod_cutting.h cache.h

# helpers.o: helpers.c error_handling.h

# error_handling.o: error_handling.c

# rod_cutting.o: rod_cutting.c

# cache.o: cache.c cache.h
# clean:
# 	rm -f main $(OBJS)
all: testin

OBJS = testin.o bst_node.o
CC = clang
CFLAGS = -g -Wall

testin: $(OBJS)
	clang -o testin $(CFLAGS) $(OBJS)

testin.o: testin.c bst_node.h

bst_node.o: bst_node.c bst_node.h

clean:
	rm -f testin $(OBJS)