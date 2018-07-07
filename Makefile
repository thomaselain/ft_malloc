# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: telain <telain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/22 17:19:39 by telain            #+#    #+#              #
#    Updated: 2016/06/23 19:33:22 by telain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_malloc
PATH_SRC := src/
INC := -I includes/

CC := gcc
FLAGS := $(INC) 
# -g -Wall -Wextra -Werror

SRC := 	main.c\
		ft_malloc.c\
		buckets.c\

LIBS := libft/libft.a

OBJ := $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@printf "Compiling $(NAME) ...\n"
	@$(CC) $(FLAGS) -o  $(NAME) $(OBJ) $(LIBS) -L libft/
	@printf "$(NAME) compiled\n"

%.o: %.c
	@$(CC) $(FLAGS) $(HEADERS) -c -o $@ $^
	@printf "[\e[32m$(NAME) object\e[0m]\e[32m--\e[0m--\e[32m--\e[0m> : $@"
	@printf "\e[0m\n"

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

go: re
	./$(NAME)

.PHONY: clean fclean
