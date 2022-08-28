# @author   cvidon@42
# @brief    Makefile for C programs that does not require any dependency.

INC_DIR		= include
SRC_DIR		= src

SRCS = ft_printf.c \
	   options_1.c \
	   options_2.c \
	   utils.c \

SRCS := $(SRCS:%=$(SRC_DIR)/%)
OBJS := $(SRCS:.c=.o)

NAME = libftprintf.a
CC = clang
CFLAGS = -Wall -Wextra -Werror -Wconversion -Wsign-conversion -c
CPPFLAGS = -I include

RM			= rm -rf
MAKE		= make -C
MUTE		= 1>/dev/null 2>/dev/null
CLS			= \r\033[K

.PHONY: all clean fclean re san_addr norm update

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

san_addr: CC := gcc
san_addr: CFLAGS := $(CFLAGS) -g -fsanitize=address,undefined,signed-integer-overflow
san_addr: $(NAME)

everything: CFLAGS := -Weverything
everything: $(NAME)

norm:
	@norminette | grep -v "OK" || true

update:
	@git pull
	@git submodule update --init
