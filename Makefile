#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchevall <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/26 14:43:40 by mchevall          #+#    #+#              #
#    Updated: 2016/05/19 15:12:06 by mchevall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
LIB = ft_printf/libftprintf.a
SRC = ft_error.c\
	  ft_realloc.c\
	  map_manager.c\
	  map_manager2.c\
	  only_digit.c\
	  removejunk.c\
	  list_management.c\
	  main.c
OBJ = 
SRCO = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c
	$(CC) -o $(addprefix $(OBJ),$@) -c $< $(FLAG)

$(NAME): $(SRCO)
	make -C ft_printf
	gcc -o $(NAME) $(FLAG) $(SRC) $(LIB)

clean:
	make -C ft_printf clean
	rm -f $(addprefix $(OBJ),$(SRCO))

fclean: clean
	make -C ft_printf fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
