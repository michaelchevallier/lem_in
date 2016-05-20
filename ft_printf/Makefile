# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchevall <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/26 14:43:40 by mchevall          #+#    #+#              #
#    Updated: 2016/04/25 18:17:28 by mchevall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIB = libft/libft.a
SRC = ft_printf.c\
	  specifier_finder.c\
	  format_specifier_manager.c\
	  specifier_funcs.c\
	  specifier_funcs2.c\
	  specifier_funcs3.c\
	  specifier_funcs4.c\
	  specifier_funcs5.c\
	  wchar_manager.c\
	  funcs.c\
	  funcs2.c\
	  wstr_manager.c\
	  precision_manager.c\
	  flag_manager.c\
	  width_manager.c
OBJ = 
SRCO = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c
	$(CC) -o $(addprefix $(OBJ),$@) -c $< $(CFLAGS)

$(NAME): $(SRCO)
	make -C libft
	cp $(LIB) $(NAME)
	ar r $(NAME) $(addprefix $(OBJ),$(SRCO))
	ranlib $(NAME)

clean:
	make -C libft clean
	rm -f $(addprefix $(OBJ),$(SRCO))

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
