NAME_ONE = push_swap
NAME_TWO = checker
LIBFTA = $(LIB_DIR)libft.a

LIB_DIR = libft/
HEAD_DIR = includes/

COMP =	gcc -Wall -Werror -Wextra

DIR_PS = srcs/push_swap/
DIR_CH = srcs/checker/
DIR_GEN = srcs/general/

OBJ_DIR_PS = obj_ps/
OBJ_DIR_CH = obj_ch/

SRCS_PS = extension_utils.c quick_sort.c range_pack_utils.c \
			range_utils.c sort_three_values.c push_swap_main.c \
			sorter.c
SRCS_CH = checker_main.c comand_utils.c
SRCS_GEN = instructions.c item_utils.c program_utils.c \
			stack_utils.c stack_core.c stack_invalidate.c

C_FILE_PS = $(SRCS_PS) $(SRCS_GEN)
C_FILE_CH = $(SRCS_CH) $(SRCS_GEN)

OFILE_PS =	$(C_FILE_PS:%.c=%.o)
OFILE_CH = $(C_FILE_CH:%.c=%.o)

OBJ_PS = $(addprefix $(OBJ_DIR_PS), $(OFILE_PS))
OBJ_CH = $(addprefix $(OBJ_DIR_CH), $(OFILE_CH))


all: $(NAME_ONE) $(NAME_TWO)

lib:
	@make -C $(LIB_DIR)

$(OBJ_DIR_PS):
	@mkdir -p $(OBJ_DIR_PS)
$(OBJ_DIR_CH):
	@mkdir -p $(OBJ_DIR_CH)

$(NAME_ONE): $(OBJ_DIR_PS) $(OBJ_PS)
	@echo -------compile push swap begin--------
	@make -C $(LIB_DIR)
	@$(COMP) $(OBJ_PS) $(LIBFTA) -D PS_VERBOSE=1 -o $(NAME_ONE)
	@echo -------compile push swap finish--------

$(NAME_TWO): $(OBJ_DIR_CH) $(OBJ_CH)
	@echo -------compile checker begin--------
	@make -C $(LIB_DIR)
	@$(COMP) -g $(OBJ_CH) $(LIBFTA) -D PS_VERBOSE=1 -o $(NAME_TWO)
	@echo -------compile checker finish----------

$(OBJ_DIR_PS)%.o: $(DIR_PS)%.c
	@$(COMP) -c $< -o $@
$(OBJ_DIR_PS)%.o: $(DIR_GEN)%.c
	@$(COMP) -D PS_VERBOSE=1 -c $< -o $@

$(OBJ_DIR_CH)%.o: $(DIR_CH)%.c
	@$(COMP) -c $< -o $@
$(OBJ_DIR_CH)%.o: $(DIR_GEN)%.c
	@$(COMP) -c $< -o $@ 

clean:
	@/bin/rm -rf $(OBJ_DIR_PS)
	@/bin/rm -rf $(OBJ_DIR_CH)
	@make -C $(LIB_DIR) clean
	@echo OBJECTS FILES HAS BEEN DELETED.

fclean: clean
	@/bin/rm -f $(NAME_ONE)
	@/bin/rm -f $(NAME_TWO)
	@make -C $(LIB_DIR) fclean
	@echo OBJECT FILES AND EXECUTABLE HAS BEEN DELETED.

re: fclean all

# test:
# 	gcc *.c ./libft/libft.a test/test.c -g
# checker:
# 	gcc *.c checker/checker_main.c ./libft/libft.a -g -D PS_VERBOSE=0
# push_swap:
# 	gcc -Wall -Wextra -Werror *.c ./sort_algorithms/sort_three_values.c push_swap/*.c ./libft/libft.a -g -D PS_VERBOSE=1