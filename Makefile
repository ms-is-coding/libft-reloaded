# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 21:10:40 by smamalig          #+#    #+#              #
#    Updated: 2025/02/14 02:53:56 by smamalig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libft.a
CC          = cc
CPP			= c++
CFLAGS      = -Wall -Wextra -Werror -O3
SRCS        = $(shell find . -type f -name '*.c')
TEST_SRCS	= $(shell find . -type f -name '*.cpp')
OBJS        = $(SRCS:%.c=%.o)
TEST_OBJS	= $(TEST_SRCS:%.cpp=%.o)
INCLUDES    = -Iinclude
HEADER      = include/libft.h

# Colors
RED         = \033[0;31m
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
BLUE        = \033[0;34m
MAGENTA     = \033[0;35m
CYAN        = \033[0;36m
BOLD		= \033[1m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(BOLD)$(BLUE)%12s$(RESET): $(YELLOW)Building$(RESET) $(NAME)\n" $(NAME)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	@printf "$(BLUE)%12s$(RESET): $(MAGENTA)Compiling$(RESET) $<\n" $(NAME)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.cpp $(HEADER)
	@printf "$(BLUE)%12s$(RESET): $(MAGENTA)Compiling$(RESET) $<\n" $(NAME)
	@$(CPP) $(INCLUDES) -c $< -o $@

test: $(OBJS) $(TEST_OBJS) $(HEADER)
	@$(CPP) $(TEST_OBJS) $(OBJS) -o test
	@printf "$(BOLD)$(BLUE)%12s$(RESET): $(CYAN)Running$(RESET) $(NAME)\n" $(NAME)
	@./test
	@rm test

clean:
	@printf "$(BOLD)$(BLUE)%12s$(RESET): $(RED)Removing$(RESET) object files\n" $(NAME)
	@rm -rf $(OBJS)

fclean: clean
	@printf "$(BOLD)$(BLUE)%12s$(RESET): $(RED)Removing$(RESET) executables and libraries\n" $(NAME)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft header
