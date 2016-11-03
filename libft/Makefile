CC = gcc
CFLAG = -Wall -Wextra -Werror
HDIR = include
SRC = ft_atoi.c ft_bzero.c ft_check_charset.c \
ft_chisdigit.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_itoa.c ft_lastch_pos.c ft_memalloc.c \
ft_memccpy.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memdel.c ft_memmove.c \
ft_memset.c ft_nextch_pos.c \
ft_pow.c ft_putchar.c ft_putchar_fd.c \
ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
ft_size_base.c ft_strcat.c ft_strchr.c \
ft_strclr.c ft_strcmp.c ft_strcpy.c \
ft_strdel.c ft_strdup.c ft_strequ.c \
ft_striter.c ft_striteri.c ft_strjoin.c \
ft_strlcat.c ft_strlen.c ft_strmap.c \
ft_strmapi.c ft_strncat.c ft_strncmp.c \
ft_strncpy.c ft_strnequ.c ft_strnew.c \
ft_strnstr.c ft_strrchr.c ft_strsplit.c \
ft_strstr.c ft_strsub.c ft_strtrim.c \
ft_tolower.c ft_toupper.c ft_sqrt.c \
ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
ft_lstadd.c ft_lstiter.c ft_lstmap.c \
ft_putstr_right.c ft_putstr_left.c ft_putendchar.c \
ft_getnbr.c ft_strisnum.c get_next_line.c \
ft_select_charset.c ft_strstr_split.c ft_lstadd_back.c \
ft_wordnb.c ft_strlen_str.c ft_clean.c ft_lstcount.c ft_strinsert.c \
ft_abs.c ft_lstcpy.c ft_lstrotate.c ft_lstrev_rotate.c ft_lstswap.c \
ft_lstpush.c ft_lsttrans.c ft_trnew.c ft_trdelone.c ft_trdel.c \
ft_lstdel_addr.c ft_lstdel_range.c ft_lstadd_range.c ft_lstrev.c \
ft_maxint.c
SRC_DIR = ./src
SRC_C = $(patsubst %, $(SRC_DIR)/%, $(SRC))
OBJ = $(patsubst %.c, %.o, $(SRC))
OBJ_DIR = ./obj
OBJ_O = $(patsubst %, $(OBJ_DIR)/%, $(OBJ))
NAME = libft.a
.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	@$(CC) -c $< -o $@ -I $(HDIR) $(CFLAG)

$(NAME): $(OBJ_DIR) $(OBJ_O)
	@ar -rc $(NAME) $(OBJ_O)
	@echo "\033[32mlibft compiled\033[0m"

$(OBJ_DIR):
	@mkdir $@

clean:
	@rm -rf $(OBJ_O) $(OBJ_DIR)
	@echo "\033[31mlibft object file removed\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31mlibft.a removed\033[0m"
re: fclean all
