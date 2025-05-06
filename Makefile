# Executable names
NAME_S = server
NAME_C = client
NAME_SB = server_bonus
NAME_CB = client_bonus

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# ft_printf directory
FT_PRINTF_DIR = ./ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a
FT_PRINTF_INC = -I$(FT_PRINTF_DIR)

# Source files
SRC_S = server.c
SRC_C = client.c
SRC_SB = server_bonus.c
SRC_CB = client_bonus.c
SRC_U = utils.c

# Targets
all: $(FT_PRINTF_LIB) $(NAME_S) $(NAME_C)

bonus: $(FT_PRINTF_LIB) $(NAME_SB) $(NAME_CB)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME_S): $(SRC_S) $(SRC_U)
	$(CC) $(CFLAGS) $(SRC_S) $(SRC_U) $(FT_PRINTF_LIB) $(FT_PRINTF_INC) -o $(NAME_S)

$(NAME_C): $(SRC_C) $(SRC_U)
	$(CC) $(CFLAGS) $(SRC_C) $(SRC_U) $(FT_PRINTF_LIB) $(FT_PRINTF_INC) -o $(NAME_C)

$(NAME_SB): $(SRC_SB) $(SRC_U)
	$(CC) $(CFLAGS) $(SRC_SB) $(SRC_U) $(FT_PRINTF_LIB) $(FT_PRINTF_INC) -o $(NAME_SB)

$(NAME_CB): $(SRC_CB) $(SRC_U)
	$(CC) $(CFLAGS) $(SRC_CB) $(SRC_U) $(FT_PRINTF_LIB) $(FT_PRINTF_INC) -o $(NAME_CB)

clean:
	$(MAKE) clean -C $(FT_PRINTF_DIR)
	rm -f $(NAME_S) $(NAME_C) $(NAME_SB) $(NAME_CB)

fclean: clean
	$(MAKE) fclean -C $(FT_PRINTF_DIR)

re: fclean all

.PHONY: all bonus clean fclean re
