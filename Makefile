#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchevall <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/26 14:43:40 by mchevall          #+#    #+#              #
#    Updated: 2016/06/30 14:34:50 by mchevall         ###   ########.fr        #
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
	  matrix_initialiser.c\
	  matrix_manager.c\
	  index_initialiser.c\
	  find_paths.c\
	  paths_finder.c\
	  paths_finder_aux.c\
	  ants_maker.c\
	  ant_mover.c\
	  solve.c\
	  erase_all_connection.c\
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
