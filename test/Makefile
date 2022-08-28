# @author   cvidon@42
# @brief    Makefile for C programs compiling with a library.

NAME		= printfest
LIBFTPRINTF	= ..

CC			= clang
CFLAGS		= -Wall -Wextra -Werror -Wconversion

CPPFLAGS	= -I $(LIBFTPRINTF)/include
LDFLAGS		= -L $(LIBFTPRINTF)
LDLIBS		= -l ftprintf

SRCS		= printfest.c
OBJS		:= $(SRCS:%.c=%.o)

RM			= rm -rf
MAKE		= make -C
MUTE		= 1>/dev/null 2>/dev/null
CLS			= \r\033[K

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	@echo "$(CLS)>>> SUCCESS <<<"

%.o: %.c
	@echo -n "$(CLS)Building printfest..."
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo -n "$(CLS)Building libftprintf..."
	@$(MAKE) $(LIBFTPRINTF) $(MUTE)

clean:
	@$(MAKE) $(LIBFTPRINTF) clean $(MUTE)
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) $(LIBFTPRINTF) fclean $(MUTE)
	@$(RM) $(NAME)

re: fclean all

san_thread: CC := gcc
san_thread: CFLAGS := $(CFLAGS) -g -fsanitize=thread,undefined,signed-integer-overflow
san_thread: $(NAME)

everthing: CFLAGS := -Weverything
everthing: $(NAME)

test: re
	@./$(NAME) || true

.PHONY: all clean fclean re san_thread
