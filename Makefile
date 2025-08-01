NAME = libftprintf.a
all: $(NAME)

$(NAME):
	cc -Wall -Wextra -Werror -c ft_printf_handle.c ft_printf_handle2.c ft_printf_hex.c \
	ft_printf_itoa.c ft_printf_str_tools.c ft_printf.c
	ar rcs libftprintf.a ft_printf_handle.o ft_printf_handle2.o ft_printf_hex.o \
	ft_printf_itoa.o ft_printf_str_tools.o ft_printf.o
clean:
	rm -f ft_printf_handle.o ft_printf_handle2.o ft_printf_hex.o \
	ft_printf_itoa.o ft_printf_str_tools.o ft_printf.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
