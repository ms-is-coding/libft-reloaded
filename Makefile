# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 21:10:40 by smamalig          #+#    #+#              #
#    Updated: 2025/04/06 23:56:50 by smamalig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libft.a
CC          = cc
CPP         = c++
CFLAGS      = -Wall -Wextra -Werror -O3
SRCS        = $(shell find src -type f -name '*.c')
TEST_SRCS   = $(shell find tests -type f -name '*.cpp')
OBJ_DIR     = obj
OBJS        = $(patsubst src/%.c, ${OBJ_DIR}/%.o, $(SRCS))
TEST_OBJS   = $(patsubst tests/%.cpp, $(OBJ_DIR)/%.o, $(TEST_SRCS))
INCLUDES    = -Iinclude
HEADER      = include/libft.h
LIBS        = -lbsd

# Colors
RED         = \e[31m
GREEN       = \e[32m
YELLOW      = \e[33m
BLUE        = \e[34m
MAGENTA     = \e[35m
CYAN        = \e[36m
RESET       = \e[m

all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(BLUE)%s$(RESET): $(YELLOW)Building$(RESET) $(NAME)\n" $(NAME)
	@ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: src/%.c $(HEADER)
	@mkdir -p $(dir $@)
	@printf "$(BLUE)%s$(RESET): $(MAGENTA)Compiling$(RESET) $<\n" $(NAME)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: tests/%.cpp $(HEADER)
	@printf "$(BLUE)%s$(RESET): $(MAGENTA)Compiling$(RESET) $<\n" $(NAME)
	@$(CPP) $(INCLUDES) -c $< -o $@

norm:
	@-norminette | grep -v "OK"

test: $(OBJS) $(TEST_OBJS) $(HEADER)
	@$(CPP) $(TEST_OBJS) $(OBJS) $(LIBS)
	@printf "$(BLUE)%s$(RESET): $(CYAN)Running$(RESET) $(NAME)\n" $(NAME)
	@./a.out

clean:
	@printf "$(BLUE)%s$(RESET): $(RED)Removing$(RESET) object files\n" $(NAME)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@printf "$(BLUE)%s$(RESET): $(RED)Removing$(RESET) executables and libraries\n" $(NAME)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re norm
