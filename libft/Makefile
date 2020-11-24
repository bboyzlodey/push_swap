# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asybil <asybil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 18:21:37 by asybil            #+#    #+#              #
#    Updated: 2020/11/23 04:50:05 by asybil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putstr.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_putstr_fd.c ft_putnbr_fd.c ft_putchar_fd.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstnew.c ft_itoa.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_strsplit.c get_next_line.c \
		 ft_strappend.c functions_que.c find_1.c find_2.c ft_integers.c calculate_managment.c calculate.c flag_management_2.c \
flag_management.c ft_printf.c precision_management.c size_management.c size_management_2.c \
string.c t_long_num.c t_long_num_2.c t_long_num_str.c calculate.c t_long_num_util.c t_long_num_util_2.c \
utils.c width_management.c ft_double.c ft_double_2.c ft_long_double.c t_long_num_3.c

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRCS:.c=.o)

all: $(NAME)

%.o : %.c libft.h
	$(CC) -c $(FLAGS) $<

$(NAME): $(OBJ)
	@ar rc $@ $^

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
