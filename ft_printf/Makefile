CC = gcc
CFLAG = -Wall -Wextra -Werror
HDIR = include
SRC = ft_printf.c parse_width.c parse_attr.c print_nbr.c print_str.c parse_pres.c \
size_base.c putlong_char.c putlong_nbr.c putlun_nbr.c putshort_nbr.c putchar_nbr.c \
print_space_left.c parse_modifier.c atoi_base.c putint_base.c tool.c szb.c bzero.c \
putnbr.c print.c putlong_base.c putstr_pres.c print_zero_left.c print_choice.c \
print_var.c tool_2.c
SRC_DIR = ./src
SRC_C = $(patsubst %, $(SRC_DIR)/%, $(SRC))
OBJ = $(patsubst %.c, %.o, $(SRC))
OBJ_DIR = ./obj
OBJ_O = $(patsubst %, $(OBJ_DIR)/%, $(OBJ))
OBJ_LIB = ft_putchar.o ft_putstr.o ft_atoi.o ft_check_charset.o ft_pow.o \
ft_size_base.o ft_strchr.o ft_strlen.o ft_chisdigit.o ft_strcmp.o
LIB = ../libft/libft.a
NAME = libftprintf.a
.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c $< -o $@ -I $(HDIR) $(CFLAG)

$(NAME): $(OBJ_DIR) $(OBJ_LIB) $(OBJ_O)
	@ar -rc $(NAME) $(OBJ_O)
	@echo "\033[32m$(NAME) compiled\033[0m"
	@rm -rf $(OBJ_LIB)

ft_%.o:
	@ar -x $(LIB) $@

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_O)
	@rm -rf $(OBJ_DIR)
	@echo "\033[31m$(NAME) object file removed\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31m$(NAME) removed\033[0m"
re: fclean all
