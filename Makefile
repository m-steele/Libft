

SRCS = ft_bzero.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c int ft_isprint.c ft_memset.c \
ft_strlen.c ft_memcpy.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRCS:.c=.o)
NAME = libft.a

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)