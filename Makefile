test:
	gcc *.c ./libft/libft.a test/test.c -g
checker:
	gcc *.c checker/checker_main.c ./libft/libft.a -g -D PS_VERBOSE=0
push_swap:
	gcc *.c ./sort_algorithms/sort_three_values.c push_swap/*.c ./libft/libft.a -g -D PS_VERBOSE=1 -o push_swap1