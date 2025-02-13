# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 21:10:40 by smamalig          #+#    #+#              #
#    Updated: 2025/02/13 22:41:37 by smamalig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libft.a
CC          = cc
CPP			= c++
CFLAGS      = -Wall -Wextra -Werror -O3
SRCS        = $(shell find . -type f -name '*.c')
OBJS        = $(SRCS:%.c=%.o)
INCLUDES    = -Iinclude
HEADER      = include/libft.h

# Progress tracking
TOTAL       = $(words $(SRCS))
COUNTER     = $(words $(shell find . -type f -name '*.o'))
PROGRESS    = $(eval COUNTER=$(shell expr $(COUNTER) + 1)) \
              $(shell echo "scale=2; $(COUNTER)*100/$(TOTAL)" | bc)

# Colors
RED         = \033[0;31m
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
BLUE        = \033[0;34m
MAGENTA     = \033[0;35m
CYAN        = \033[0;36m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@printf "$(GREEN)Successfully built $(NAME)!$(RESET)\n\n"

%.o: %.c $(HEADER)
	@printf "$(MAGENTA)Compiling$(RESET) $<       \n"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.cpp $(HEADER)
	@printf "$(MAGENTA)Compiling$(RESET) $<       \n"
	@$(CPP) $(INCLUDES) -c $< -o $@

clean:
	@printf "$(RED)Cleaning object files...$(RESET)\n"
	@rm -rf $(OBJS)

fclean: clean
	@printf "$(RED)Full clean...$(RESET)\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft header
