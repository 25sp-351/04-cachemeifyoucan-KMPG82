all: main

OBJS = main.o helpers.o error_handling.o rod_cutting.o cache_policy_a.o bst_node.o linked_list.o linked_list_node.o
CC = clang
CFLAGS = -g -Wall

main: $(OBJS)
	clang -o policy_a $(CFLAGS) $(OBJS)

main.o: main.c helpers.h error_handling.h rod_cutting.h cache_policy_a.h

helpers.o: helpers.c error_handling.h

error_handling.o: error_handling.c

rod_cutting.o: rod_cutting.c

bst_node.o: bst_node.c bst_node.h

linked_list.o: linked_list.c linked_list.h linked_list_node.h

linked_list_node.o: linked_list_node.c linked_list_node.h

cache_policy_a.o: cache_policy_a.c cache_policy_a.h bst_node.h linked_list.h

clean:
	rm -f policy_a $(OBJS)

# all: testin

# OBJS = testin.o linked_list.o linked_list_node.o
# CC = clang
# CFLAGS = -g -Wall

# testin: $(OBJS)
# 	clang -o testin $(CFLAGS) $(OBJS)

# testin.o: testin.c linked_list.h

# linked_list.o: linked_list.c linked_list.h linked_list_node.h

# linked_list_node.o: linked_list_node.c linked_list_node.h

# clean:
# 	rm -f testin $(OBJS)