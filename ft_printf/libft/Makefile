# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchevall <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 16:28:30 by mchevall          #+#    #+#              #
#    Updated: 2016/04/19 16:28:46 by mchevall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
SRC = ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlen.c\
ft_strncat.c ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_strncmp.c\
ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
ft_toupper.c ft_tolower.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c\
ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlcat.c ft_putchar.c ft_putstr.c\
ft_putendl.c ft_putnbr.c ft_itoa.c ft_memalloc.c ft_memdel.c ft_strclr.c\
ft_strdel.c ft_strnew.c ft_striteri.c ft_striter.c ft_putstr_fd.c\
ft_putendl_fd.c ft_putchar_fd.c ft_putnbr_fd.c ft_strmap.c ft_strmapi.c\
ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c\
ft_2dtab.c ft_strsplit.c ft_strrev.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c\
ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_sort_int_tab.c ft_isprime.c\
ft_foreach.c clean_open.c clean_read.c get_next_line.c ft_countwords.c\
ft_lenwords.c ft_error.c ft_itoa_base.c ft_itoa_baseuint.c\
ft_strjoin_and_free.c ft_stringupper.c ft_ustrcat.c ft_ustrdel.c\
ft_ustrjoin_and_free.c  ft_uustrjoin_and_free.c ft_ustrlen.c ft_ustrnew.c\
ft_uustrcat.c ft_ustrsub.c ft_wcharlen.c ft_uputchar.c ft_uputstr.c\
ft_uatoi.c ft_intmaxuatoi.c ft_uintmaxuatoi.c ft_ustrdup.c ft_intmaxatoi.c
OBJ = 
SRCO = $(SRC:.c=.o)
HEADERS = includes
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

re: fclean all

%.o: %.c
	$(CC) -o $(addprefix $(OBJ),$@) -c $< $(CFLAGS) -I includes

$(NAME): $(SRCO)
	ar rc $(NAME) $(addprefix $(OBJ),$(SRCO))
	ranlib $@

clean:
	rm -f $(addprefix $(OBJ),$(SRCO))

fclean: clean
	rm -f $(NAME)

.PHONY: re clean fclean all
