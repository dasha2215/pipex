NAME = pipex

SRC_DIR = src
SRC_FILES = main.c args.c pipex.c utils.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:.c=.o)
HEADER = include/pipex.h

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

MYLIB_DIR = mylib
MYLIB = $(MYLIB_DIR)/mylib.a

all: $(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(MYLIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MYLIB)

$(MYLIB):
	@make -C $(MYLIB_DIR)

clean:
	$(RM) $(OBJ)
	@make clean -C $(MYLIB_DIR)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(MYLIB_DIR)

re: fclean all

.PHONY: all clean fclean re
