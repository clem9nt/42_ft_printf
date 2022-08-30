# @file     Makefile
# @brief    Simple Makefile for C lib tester.
# @author   clemedon (Clément Vidon)

NAME		:= printfest
LIB			:= ..

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#
# CC        compiler
# CFLAGS    compiler flags
# CPPFLAGS  preprocessor flags
# SRCS      source files
# OBJS      object files

CC			:= clang
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -I $(LIB)/include
LDFLAGS		:= -L $(LIB)
LDLIBS		:= -l ftprintf
SRCS		:= printfest.c
OBJS		:= $(SRCS:%.c=%.o)

#------------------------------------------------#
#   UTENSILS                                     #
#------------------------------------------------#
# RM        cleaning command
# MAKE      other Makefile call command
# RULE      other Makefile call rule
# VALGRIND  valgrind command
# CLS       clear the current line
# MUTE      mute the stdout

RM			:= rm -rf
MAKE		:= make --directory
RULE		:= all
VALGRIND	:= valgrind -q --leak-check=yes --show-leak-kinds=all
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
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	@echo "$(CLS)$(NAME) created."

%.o: %.c
	@echo -n "$(CLS)Building $(NAME)..."
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@$(MAKE) $(LIB) $(RULE) $(MUTE)

clean:
	@$(MAKE) $(LIB) clean $(MUTE)
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) $(LIB) fclean $(MUTE)
	@$(RM) $(NAME)

re: fclean all

#------------------------------------------------#
#   CUSTOM RECIPES                               #
#------------------------------------------------#
# sana          memory corruption debugging
# ansi          ANSI Std89 compliance
# every         explore new warnings
# info          standard build output
# run           run the program

.PHONY: sana ansi every info run

sana: CC		:= gcc
sana: RULE		:= sana
sana: CFLAGS	+= -g -fsanitize=address,undefined,signed-integer-overflow
sana: $(NAME)

ansi: CFLAGS	+= -W -Wcast-qual -Wcomma -Wconversion -Wsign-conversion -Wwrite-strings -pedantic -std=c89
ansi: RULE		:= ansi
ansi: $(NAME)

every: CFLAGS	+= -Weverything
every: RULE		:= every
every: $(NAME)

info: fclean
	@make --dry-run | grep -v "echo.*\".*\"\|\[.*\]"

run: re
	@$(VALGRIND) ./$(NAME) || true
