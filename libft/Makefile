# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/28 21:06:57 by dsusheno          #+#    #+#              #
#    Updated: 2016/03/04 17:21:12 by dsusheno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_putnbr.c\
	  ft_putstrn.c\
	  get_next_line.c\
	  ft_strjoin_char_free.c\
	  ft_strjoin_char.c\
	  ft_strjoin_free.c\
	  ft_strndup.c\
	  ft_swap.c\
	  ft_iterative_power.c\
	  ft_lstaddend.c\
	  ft_isspace.c\
	  ft_itoa.c\
	  ft_lstiter.c\
	  ft_lstmap.c\
	  ft_lstadd.c\
	  ft_lstdel.c\
	  ft_lstdelone.c\
	  ft_lstnew.c\
	  ft_putnbr_fd.c\
	  ft_putendl_fd.c\
	  ft_putstr_fd.c\
	  ft_putchar_fd.c\
	  ft_isalnum.c\
	  ft_isprint.c\
	  ft_memcpy.c\
	  ft_strchr.c\
	  ft_strlcat.c\
	  ft_strncpy.c\
	  ft_tolower.c\
	  ft_isalpha.c\
	  ft_memccpy.c\
	  ft_memmove.c\
	  ft_strcmp.c\
	  ft_strlen.c\
	  ft_strnstr.c\
	  ft_toupper.c\
	  ft_atoi.c\
	  ft_isascii.c\
	  ft_memchr.c\
	  ft_memset.c\
	  ft_strcpy.c\
	  ft_strncat.c\
	  ft_strrchr.c\
	  ft_bzero.c\
	  ft_isdigit.c\
	  ft_memcmp.c\
	  ft_strcat.c\
	  ft_strdup.c\
	  ft_strncmp.c\
	  ft_strstr.c\
	  ft_memalloc.c\
	  ft_memdel.c\
	  ft_strnew.c\
	  ft_strdel.c\
	  ft_strclr.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strequ.c\
	  ft_strnequ.c\
	  ft_strsub.c\
	  ft_strjoin.c\
	  ft_strtrim.c\
	  ft_strsplit.c\
	  ft_putchar.c\
	  ft_putstr.c\
	  ft_putendl.c

OBJ = $(SRC:.c=.o)

HEADER = $(NAME:.a=.h)

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) :
	gcc -Werror -Wall -Wextra -I ./includes/ -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
