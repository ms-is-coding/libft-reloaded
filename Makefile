# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 21:10:40 by smamalig          #+#    #+#              #
#    Updated: 2025/07/17 16:39:58 by smamalig         ###   ########.fr        #
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

ifeq ($(DEBUG), 1)
	CFLAGS += -O0 -g3 -D_DEBUG \
			  -Wpedantic -Wmissing-declarations -Wpadded -Wshadow \
			  -Wconversion -Wstrict-prototypes -Wmissing-prototypes \
			  -Wold-style-definition
else
	CFLAGS += -std=c99 -O3 -DNDEBUG -Werror -march=native -flto
endif

ifeq ($(USE_ERRNO), 1)
	CFLAGS += -DUSE_ERRNO
endif

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

norm:
	@-norminette | grep -v "OK"

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	@make all --no-print-directory

-include $(DEPS)

.PHONY: all clean fclean re norm
