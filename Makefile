# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 21:10:40 by smamalig          #+#    #+#              #
#    Updated: 2025/07/15 09:57:39 by smamalig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libft.a
CC          = cc
CFLAGS      = -Wall -Wextra -MMD -MP -O0
SRC_DIR     = src
OBJ_DIR     = obj
SRCS        = $(shell find $(SRC_DIR) -type f -name '*.c')
OBJS        = $(patsubst $(SRC_DIR)/%.c, ${OBJ_DIR}/%.o, $(SRCS))
DEPS        = $(patsubst $(SRC_DIR)/%.c, ${OBJ_DIR}/%.d, $(SRCS))
INCLUDES    = -Iinclude

# Colors
RED         = \e[31m
GREEN       = \e[32m
YELLOW      = \e[33m
BLUE        = \e[34m
MAGENTA     = \e[35m
CYAN        = \e[36m
RESET       = \e[m

ifeq ($(DEBUG), 1)
	CFLAGS += -Wpedantic -g3 -Wmissing-declarations -Wpadded -Wshadow -std=c99 \
			  -Wconversion -Wstrict-prototypes -Wmissing-prototypes \
			  -Wold-style-definition
else
	CFLAGS += -Werror
endif

ifeq ($(USE_ERRNO), 1)
	CFLAGS += -DUSE_ERRNO
endif

all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(BLUE)%s$(RESET): $(YELLOW)Building$(RESET) $(NAME)\n" $(NAME)
	@ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@printf "$(BLUE)%s$(RESET): $(MAGENTA)Compiling$(RESET) $<\n" $(NAME)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

norm:
	@-norminette | grep -v "OK"

clean:
	@printf "$(BLUE)%s$(RESET): $(RED)Removing$(RESET) object files\n" $(NAME)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@printf "$(BLUE)%s$(RESET): $(RED)Removing$(RESET) executables and libraries\n" $(NAME)
	@rm -f $(NAME)

re: fclean
	@make all --no-print-directory

-include $(DEPS)

.PHONY: all clean fclean re norm
