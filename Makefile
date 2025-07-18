# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 21:10:40 by smamalig          #+#    #+#              #
#    Updated: 2025/07/18 10:22:53 by smamalig         ###   ########.fr        #
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
NPROC       = $(shell nproc)

ifeq ($(DEBUG), 1)
	CFLAGS += -O2 -g3 -D_DEBUG \
			  -Wpedantic -Wmissing-declarations -Wpadded -Wshadow \
			  -Wconversion -Wstrict-prototypes -Wmissing-prototypes \
			  -Wold-style-definition -Winline -Wsign-conversion -Wundef \
			  -Wcast-align -Wcast-qual -Wwrite-strings -Wuninitialized \
			  -Wdouble-promotion -Wfloat-equal -Wvla -Wnull-dereference \
			  -Wformat=2
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
	@if [ "$(DEBUG)" = "1" ]; then \
		clang-tidy $< -p . $(CLANG_TIDY_FLAGS); \
	fi

norm:
	echo $(SRCS) | xargs -n1 -P$(NPROC) norminette

tidy:
	echo $(SRCS) | xargs -n1 -P$(NPROC) clang-tidy -p .

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	@make all --no-print-directory

-include $(DEPS)

.PHONY: all clean fclean re norm tidy
