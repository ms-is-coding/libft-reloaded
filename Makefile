# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 21:10:40 by smamalig          #+#    #+#              #
#    Updated: 2025/02/23 15:52:21 by smamalig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libft.a
CC          = cc
CPP			= c++
CFLAGS      = -Wall -Wextra -Werror -O3
SRCS        = $(shell find src -type f -name '*.c')
TEST_SRCS	= $(shell find tests -type f -name '*.cpp')
OBJ_DIR		= obj
OBJS        = $(patsubst src/%.c, ${OBJ_DIR}/%.o, $(SRCS))
TEST_OBJS   = $(patsubst tests/%.cpp, $(OBJ_DIR)/%.o, $(TEST_SRCS))
INCLUDES    = -Iinclude
HEADER      = include/libft.h
LIBS		= -lbsd

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

$(OBJ_DIR)/%.o: src/%.c $(HEADER)
	@mkdir -p $(dir $@)
	@printf "$(BLUE)%12s$(RESET): $(MAGENTA)Compiling$(RESET) $<\n" $(NAME)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: tests/%.cpp $(HEADER)
	@printf "$(BLUE)%12s$(RESET): $(MAGENTA)Compiling$(RESET) $<\n" $(NAME)
	@$(CPP) $(INCLUDES) -c $< -o $@

norm:
	@-norminette | grep -v "OK"

test: $(OBJS) $(TEST_OBJS) $(HEADER)
	@$(CPP) $(TEST_OBJS) $(OBJS) $(LIBS) -o test
	@printf "$(BOLD)$(BLUE)%12s$(RESET): $(CYAN)Running$(RESET) $(NAME)\n" $(NAME)
	@./test
	@rm test

clean:
	@printf "$(BOLD)$(BLUE)%12s$(RESET): $(RED)Removing$(RESET) object files\n" $(NAME)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@printf "$(BOLD)$(BLUE)%12s$(RESET): $(RED)Removing$(RESET) executables and libraries\n" $(NAME)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re norm
