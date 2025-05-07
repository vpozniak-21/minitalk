NAME = libftprintf.a
AR = ar rcs
CC = cc
CFLAGS = -Werror -Wextra -Wall
SRC = ft_printf.c helper_func.c spec_handling.c
OBJ = $(SRC:.c=.o)
HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
