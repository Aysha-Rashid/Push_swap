NAME= push_swap

SRC=main.c \
	init.c \
	utils.c \
	utils_2.c \
	sorting.c \
	rotations.c \
	instructions.c \
	both_instructions.c \

OBJ= $(SRC:.c=.o)
ft_printf_lib= ft_printf/libftprintf.a
libft_lib= libft/libft.a
CC = cc

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	cd ft_printf && make all
	cd libft && make all
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(ft_printf_lib) $(libft_lib)

all: $(NAME)

clean:
	rm -rf $(OBJ)
	cd ft_printf && make clean
	cd libft && make clean

fclean: clean
	rm -rf $(NAME)
	cd ft_printf && make fclean
	cd libft && make fclean

re: fclean all