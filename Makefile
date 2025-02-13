# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 21:10:40 by smamalig          #+#    #+#              #
#    Updated: 2025/02/13 22:25:29 by smamalig         ###   ########.fr        #
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
PADDING		= $(shell echo "                ")

# Progress bar
define progress_bar
    width=20; \
    progress=$(shell echo $(PROGRESS) | cut -d. -f1); \
	filled=`bash -c "echo '$$progress * $$width / 100' | bc"`; \
	printf "\033[F📦 ["; \
    i=0; \
	while [ $$i -lt $$filled ]; do printf "#"; i=$$(($$i+1)); done; \
    printf "$(RESET)"; \
    i=$$filled; \
	while [ $$i -lt $$width ]; do printf "-"; i=$$(($$i+1)); done; \
    printf "]$(CYAN) %3.0f%%$(RESET) " $$progress
endef

all: header $(NAME)

header:
	@if ! echo "$(MAKEFLAGS)" | grep -q 'j'; then \
		printf "$(CYAN)"; \
		printf "         :::      ::::::::\n"; \
		printf "       :+:      :+:    :+:\n"; \
		printf "     +:+ +:+         +:+  \n"; \
		printf "   +#+  +:+       +#+     \n"; \
		printf " +#+#+#+#+#+   +#+        \n"; \
		printf "      #+#    #+#          \n"; \
		printf "     ###   ########.fr    \n"; \
		printf "$(RESET)\n\n"; \
	else \
		printf "$(BLUE)🔨 Building $(NAME)...$(RESET)\n"; \
	fi

$(NAME): $(OBJS)
	@printf "$(YELLOW)🔗 Linking $(NAME)...$(RESET)\n"
	@ar rcs $(NAME) $(OBJS)
	@printf "$(GREEN)✅ Successfully built $(NAME)!$(RESET)\n\n"

%.o: %.c $(HEADER)
	@$(progress_bar)
	@printf "$(MAGENTA)Compiling$(RESET) $<       \n"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.cpp $(HEADER)
	@$(progress_bar)
	@printf "$(MAGENTA)Compiling$(RESET) $<       \n"
	@$(CPP) $(INCLUDES) -c $< -o $@

clean:
	@printf "$(RED)🧹 Cleaning object files...$(RESET)\n"
	@rm -rf $(OBJS)

fclean: clean
	@printf "$(RED)🔥 Full clean...$(RESET)\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft header
