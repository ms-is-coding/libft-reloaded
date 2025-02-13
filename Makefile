# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 21:10:40 by smamalig          #+#    #+#              #
#    Updated: 2025/02/13 22:51:35 by smamalig         ###   ########.fr        #
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
	@printf "$(BLUE)%12s$(RESET): $(YELLOW)Building $(NAME)...$(RESET)\n" $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@printf "$(BLUE)%12s$(RESET): $(GREEN)Successfully built $(NAME)$(RESET)\n" $(NAME)

%.o: %.c $(HEADER)
	@printf "$(BLUE)%12s$(RESET): $(MAGENTA)Compiling$(RESET) $<\n" $(NAME)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.cpp $(HEADER)
	$(pre_msg)
	@printf "$(BLUE)%12s$(RESET): $(MAGENTA)Compiling$(RESET) $<\n" $(NAME)
	@$(CPP) $(INCLUDES) -c $< -o $@

clean:
	@printf "$(BLUE)%12s$(RESET): $(RED)Cleaning object files...$(RESET)\n" $(NAME)
	@rm -rf $(OBJS)

fclean: clean
	@printf "$(BLUE)%12s$(RESET): $(RED)Full clean...$(RESET)\n" $(NAME)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft header
