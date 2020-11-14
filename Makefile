test:
	gcc *.c ./libft/libft.a test/test.c -g
checker:
	gcc *.c checker/checker_main.c ./libft/libft.a -g
push_swap:
	gcc *.c push_swap/push_swap.c ./libft/libft.a -g