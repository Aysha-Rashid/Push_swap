NAME = push_swap
BONUS_NAME = checker

SRC = init.c \
	utils.c \
	utils_2.c \
	sorting.c \
	rotations.c \
	instructions.c \
	both_instructions.c \
	main.c

BONUS = checker.c \
	init.c \
	utils.c \
	utils_2.c \
	sorting.c \
	rotations.c \
	instructions.c \
	both_instructions.c \
	get_next_line.c \
	get_next_line_utils.c

OBJ = $(SRC:.c=.o)
BONUSOBJ = $(BONUS:.c=.o)

ft_printf_lib = ft_printf/libftprintf.a
libft_lib = libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	cd ft_printf && make
	cd libft && make
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(ft_printf_lib) $(libft_lib)

all: $(NAME)

$(BONUS_NAME): $(BONUSOBJ)
	cd ft_printf && make
	cd libft && make
	$(CC) $(CFLAGS) $(BONUSOBJ) -o $(BONUS_NAME) $(ft_printf_lib) $(libft_lib)

bonus: fclean $(BONUS_NAME)

clean:
	rm -rf $(OBJ) $(BONUSOBJ)
	cd ft_printf && make clean
	cd libft && make clean

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)
	cd ft_printf && make fclean
	cd libft && make fclean

re: fclean all
