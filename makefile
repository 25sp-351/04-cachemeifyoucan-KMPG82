all: policy_a policy_b

OBJS_COMMON = main.o helpers.o error_handling.o rod_cutting.o bst_node.o

debug: CFLAGS += -DDEBUG

debug: clean all

CC = clang

CFLAGS = -g -Wall

OBJS_A = $(OBJS_COMMON) cache_policy_a.o doubly_linked_list.o doubly_linked_list_node.o

OBJS_B = $(OBJS_COMMON) cache_policy_b.o random_index.o

policy_a: $(OBJS_A)
	$(CC) -o policy_a $(CFLAGS) $(OBJS_A)

policy_b: $(OBJS_B)
	$(CC) -o policy_b $(CFLAGS) $(OBJS_B)

main.o: main.c helpers.h error_handling.h rod_cutting.h cache_policy_b.h

helpers.o: helpers.c error_handling.h

error_handling.o: error_handling.c

rod_cutting.o: rod_cutting.c

bst_node.o: bst_node.c bst_node.h

doubly_linked_list.o: doubly_linked_list.c doubly_linked_list.h doubly_linked_list_node.h

doubly_linked_list_node.o: doubly_linked_list_node.c doubly_linked_list_node.h

cache_policy_a.o: cache_policy_a.c cache_policy_a.h bst_node.h doubly_linked_list.h

cache_policy_b.o: cache_policy_b.c cache_policy_b.h bst_node.h random_index.h

random_index.o: random_index.c



clean:
	rm -f policy_a policy_b $(OBJS_COMMON) $(OBJS_A) $(OBJS_B)
