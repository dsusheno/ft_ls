# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/03 15:19:48 by dsusheno          #+#    #+#              #
#    Updated: 2016/03/04 16:31:06 by dsusheno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

DIR_H = ./incs/

DIR_C = ./src/

DIR_O = ./objs/

FILE_C = big_r.c\
		 ft_dir_list.c\
		 ft_flag.c\
		 ft_merge_arg.c\
		 ft_merge_multi.c\
		 ft_merge_sort.c\
		 ft_mode.c\
		 ft_print.c\
		 ft_sp_str.c\
		 ft_time.c\
		 ft_tri.c\
		 main.c\
		 multi_arg.c\

FILE_O = $(FILE_C:.c=.o)

SRC_C := $(addprefix $(DIR_C), $(FILE_C))

SRC_O := $(addprefix $(DIR_O), $(FILE_O))

FLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(SRC_O)
	@clang -o $(NAME) $(SRC_O) -L libft/ -lft -lncurses

$(SRC_O): $(SRC_C)
	@make -C libft/
	@clang $(FLAGS) -c $(SRC_C) -I $(DIR_H) -g
	@mkdir -p $(DIR_O)
	@mv $(FILE_O) $(DIR_O)

clean:
	@/bin/rm -rf $(DIR_O)
	@make clean -C libft/

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft/

re: fclean all

.PHONY: clean fclean all re
