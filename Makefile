# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: telain <telain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/22 17:19:39 by telain            #+#    #+#              #
#    Updated: 2018/07/09 20:54:03 by telain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_malloc
PATH_SRC := src/
INC := -I includes/

WHITE = \e[0m
GREEN = \e[32m

CC := gcc
FLAGS := $(INC) 
# -g -Wall -Wextra -Werror

SRC := 	main.c\
		ft_malloc.c\
		buckets.c\
		zones.c\

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
	@printf "[$(GREEN)$(NAME) object$(WHITE)]$(GREEN)--$(WHITE)--$(GREEN)--$(WHITE)> : [$(GREEN)✓$(WHITE)] : $@"
	@printf "$(WHITE)\n"

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

go:
	make
	./$(NAME)

.PHONY: clean fclean
