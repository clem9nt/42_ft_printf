# @file     Makefile
# @brief    Simple Makefile for C lib.
# @author   clemedon (Clément Vidon)

NAME		:= libftprintf.a

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#
# CC        compiler
# CFLAGS    compiler flags
# CPPFLAGS  preprocessor flags
#
# SRCS      source files
# OBJS      object files

CC			:= clang
CFLAGS		:= -Wall -Wextra -Werror -c
CPPFLAGS	:= -I include

SRCS		:= \
	src/ft_printf.c \
	src/options_1.c \
	src/options_2.c \
	src/utils.c
OBJS		:= $(SRCS:.c=.o)

#------------------------------------------------#
#   UTENSILS                                     #
#------------------------------------------------#
# RM        cleaning command
# CLS       clear the current line
# MUTE      mute the stdout

RM			:= rm -rf
CLS			:= \r\033[K
MUTE		:= 1>/dev/null

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#
# all       build all targets
# $(NAME)   build $(NAME) target
# clean     remove objects
# fclean    remove objects and binary
# re        remove objects and binary and rebuild all

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(CLS)$(NAME) created."

%.o: %.c
	@echo -n "$(CLS)Building $(NAME)..."
	@$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: 	clean
	@$(RM) $(NAME)

re: fclean all

#------------------------------------------------#
#   CUSTOM RECIPES                               #
#------------------------------------------------#
# sana          memory corruption debugging
# ansi          ANSI Std89 compliance
# every         explore new warnings
# update        update the repository
# norm          42 C coding style compliance
# info          standard build output

.PHONY: sana ansi every update norm info

sana: CC		:= gcc
sana: CFLAGS	+= -g -fsanitize=address,undefined,signed-integer-overflow
sana: $(NAME)

ansi: CFLAGS	+= -W -Wcast-qual -Wcomma -Wconversion -Wsign-conversion -Wwrite-strings -pedantic -std=c89
ansi: $(NAME)

every: CFLAGS	+= -Weverything
every: $(NAME)

update:
	@git pull
	@git submodule update --init

norm:
	@norminette | grep -v "OK" || true

info: fclean
	@make --dry-run | grep -v "echo.*\".*\"\|\[.*\]"
