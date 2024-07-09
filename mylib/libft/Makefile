# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsiroten <dsiroten@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 12:22:21 by dsiroten          #+#    #+#              #
#    Updated: 2024/06/14 18:02:10 by dsiroten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memchr.c ft_putstr_fd.c  ft_strncmp.c ft_strcmp.c \
ft_memcmp.c     ft_strchr.c     ft_strnstr.c \
ft_atoi.c       ft_memcpy.c     ft_strdup.c     ft_strrchr.c \
ft_bzero.c      ft_memmove.c    ft_striteri.c   ft_tolower.c \
ft_calloc.c     ft_memset.c     ft_strlcat.c    ft_toupper.c \
ft_isascii.c    ft_putchar_fd.c ft_strlcpy.c \
ft_isprint.c    ft_putendl_fd.c ft_strlen.c \
ft_itoa.c       ft_putnbr_fd.c  ft_strmapi.c ft_split.c ft_strjoin.c \
ft_strtrim.c ft_substr.c ft_isalpha.c ft_isalnum.c ft_isdigit.c
SRCBONUS = ft_lstadd_front.c ft_lstnew.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
HEADER = libft.h

OBJ = $(SRC:.c=.o)
OBJBONUS = $(SRCBONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)
%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c -o $@ $<
$(NAME): $(OBJ) $(OBJBONUS)
	ar rc $(NAME) $(OBJ) $(OBJBONUS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJBONUS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
