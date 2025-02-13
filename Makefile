# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 23:24:42 by smamalig          #+#    #+#              #
#    Updated: 2025/02/08 19:27:31 by smamalig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= cc
CPP			= c++
CFLAGS		= -Wall -Wextra -Werror -g3
SRCS		= $(shell find . -type f -name '*.c' ! -name '*_bonus.c')
BONUS		= $(shell find . -type f -name '*_bonus.c')
OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS:.c=.o)
INCLUDES	= .
HEADER		= $(INCLUDES)/libft.h

TEST_SRCS	= $(shell find . -type f -name '*.cpp')
TEST_OBJS	= $(TEST_SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

test: $(OBJS) $(TEST_OBJS) $(BONUS_OBJS)
	-norminette -R CheckDefine | grep -v OK
	$(CPP) $(CFLAGS) -I$(INCLUDES) $(OBJS) $(TEST_OBJS)
	./a.out

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TEST_OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) a.out

re: fclean all

.PHONY: all clean fclean re
