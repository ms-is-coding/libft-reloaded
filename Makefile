# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 21:10:40 by smamalig          #+#    #+#              #
#    Updated: 2025/11/14 13:52:48 by smamalig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= libft.a

SRC_DIR			:= src
TESTS_DIR		:= tests
BIN_DIR			:= bin
LIB_DIR			:= lib
BUILD_DIR		:= build

CC				:= cc
CFLAGS			:= -Wall -Wextra -MMD -MP -std=gnu23
CFLAGS_DEBUG	:= -Og -g3 -Wshadow -Wpadded -Wconversion -Wstrict-prototypes \
					-Wmissing-declarations -Wstrict-prototypes -Wundef \
					-Wmissing-prototypes -Wold-style-definition -Winline \
					-Wsign-conversion -Wcast-align -Wcast-qual -Wwrite-strings \
					-Wuninitialized -Wdouble-promotion -Wfloat-equal -Wvla \
					-Wnull-dereference -Wformat=2 -fstack-protector-strong
CFLAGS_RELEASE	:= -O2 -DNDEBUG -march=native
CFLAGS_SANITIZE	:= -fsanitize=address,undefined,leak

CXX				:= c++
CXXFLAGS		:= -O3

INCLUDES		:= -Iinclude
NPROC			:= $(shell nproc)

ifeq ($(MODE), release)
	CFLAGS += $(CFLAGS_RELEASE)
else ifeq ($(MODE), debug)
	CFLAGS += $(CFLAGS_DEBUG)
else ifeq ($(MODE), sanitize)
	CFLAGS += $(CFLAGS_DEBUG) $(CFLAGS_SANITIZE)
else
	MODE = default
	CFLAGS += -Werror
endif

ROOT_DIR	:= $(BUILD_DIR)/$(MODE)
OBJ_DIR		:= $(ROOT_DIR)/obj

SRCS		:= $(shell find $(SRC_DIR) -type f -name '*.c')
OBJS		:= $(patsubst $(SRC_DIR)/%.c, ${OBJ_DIR}/%.o, $(SRCS))
DEPS		:= $(patsubst $(SRC_DIR)/%.c, ${OBJ_DIR}/%.d, $(SRCS))

# **************************************************************************** #
# * RULES                                                                    * #
# **************************************************************************** #


.PHONY: all
all: $(NAME)
	@$(MAKE) postbuild --no-print-directory


.PHONY: default
default: all


.PHONY: release
release:
	@$(MAKE) MODE=release --no-print-directory


.PHONY: debug
debug:
	@$(MAKE) MODE=debug --no-print-directory

.PHONY: sanitize
sanitize:
	@$(MAKE) MODE=sanitize --no-print-directory


.PHONY: postbuild
postbuild:
	cp -f $(ROOT_DIR)/$(NAME) $(NAME)


$(NAME): $(OBJS)
	ar rcs $(ROOT_DIR)/$(NAME) $^


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


.PHONY: test


.PHONY: norm
norm:
	echo $(SRCS) | xargs -n1 -P$(NPROC) norminette | grep -v OK


.PHONY: tidy
tidy:
	echo $(SRCS) | xargs -n1 -P$(NPROC) clang-tidy -p .


.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)


.PHONY: fclean
fclean:
	rm -rf $(BUILD_DIR)
	rm -f $(NAME)


.PHONY: re
re: fclean
	@make all --no-print-directory


-include $(DEPS)
