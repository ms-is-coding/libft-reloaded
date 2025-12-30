# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 21:10:40 by smamalig          #+#    #+#              #
#    Updated: 2025/12/30 12:40:37 by smamalig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR			:= src
BUILD_DIR		:= build

CC				:= cc
ZIG				:= zig
AR				:= ar
ARFLAGS			:= rcs
CFLAGS			:= -Wall -Wextra -MMD -MP -std=gnu2x
CFLAGS_DEBUG	:= -Og -g3 -Wshadow -Wpadded -Wconversion -Wstrict-prototypes \
					-Wmissing-declarations -Wstrict-prototypes -Wundef \
					-Wmissing-prototypes -Wold-style-definition -Winline \
					-Wsign-conversion -Wcast-align -Wcast-qual -Wwrite-strings \
					-Wuninitialized -Wdouble-promotion -Wfloat-equal -Wvla \
					-Wnull-dereference -Wformat=2 -fstack-protector-strong
CFLAGS_RELEASE	:= -O2 -DNDEBUG -march=native
CFLAGS_SANITIZE	:= -fsanitize=address,undefined,leak

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

CORE_SRC	:= $(shell find $(SRC_DIR)/core -type f -name "*.c")
ALLOC_SRC	:= $(shell find $(SRC_DIR)/alloc -type f -name "*.c")
VECTOR_SRC	:= $(shell find $(SRC_DIR)/vector -type f -name "*.c")
PRINTF_SRC	:= $(shell find $(SRC_DIR)/printf -type f -name "*.c")
MATH_SRC	:= $(shell find $(SRC_DIR)/math -type f -name "*.c")

ALL_SRC		:= $(CORE_SRC) $(ALLOC_SRC) $(VECTOR_SRC) $(PRINTF_SRC) $(MATH_SRC)

CORE_OBJ	:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(CORE_SRC))
ALLOC_OBJ	:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(ALLOC_SRC))
VECTOR_OBJ	:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(VECTOR_SRC))
PRINTF_OBJ	:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(PRINTF_SRC))
MATH_OBJ	:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(MATH_SRC))

CORE_DEP	:= $(CORE_OBJ:.o=.d)
ALLOC_DEP	:= $(ALLOC_OBJ:.o=.d)
VECTOR_DEP	:= $(VECTOR_OBJ:.o=.d)
PRINTF_DEP	:= $(PRINTF_OBJ:.o=.d)
MATH_DEP	:= $(MATH_OBJ:.o=.d)

CORE_LIB	:= libftcore.a
ALLOC_LIB	:= libftalloc.a
VECTOR_LIB	:= libftvector.a
PRINTF_LIB	:= libftprintf.a
MATH_LIB	:= libftmath.a

INCLUDES	:= -Iinclude

# **************************************************************************** #
# * RULES                                                                    * #
# **************************************************************************** #


.PHONY: all
all: $(CORE_LIB) $(ALLOC_LIB) $(VECTOR_LIB) $(PRINTF_LIB) $(MATH_LIB)
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
	cp -f $(ROOT_DIR)/$(CORE_LIB) $(CORE_LIB)
	cp -f $(ROOT_DIR)/$(ALLOC_LIB) $(ALLOC_LIB)
	cp -f $(ROOT_DIR)/$(VECTOR_LIB) $(VECTOR_LIB)
	cp -f $(ROOT_DIR)/$(PRINTF_LIB) $(PRINTF_LIB)
	cp -f $(ROOT_DIR)/$(MATH_LIB) $(MATH_LIB)


$(CORE_LIB): $(ROOT_DIR)/$(CORE_LIB)

$(ALLOC_LIB): $(ROOT_DIR)/$(ALLOC_LIB)

$(VECTOR_LIB): $(ROOT_DIR)/$(VECTOR_LIB)

$(PRINTF_LIB): $(ROOT_DIR)/$(PRINTF_LIB)

$(MATH_LIB): $(ROOT_DIR)/$(MATH_LIB)


$(ROOT_DIR)/$(CORE_LIB): $(CORE_OBJ)
	@echo $(CORE_OBJ)
	ar rcs $@ $^


$(ROOT_DIR)/$(ALLOC_LIB): $(ALLOC_OBJ)
	ar rcs $@ $^


$(ROOT_DIR)/$(PRINTF_LIB): $(PRINTF_OBJ)
	ar rcs $@ $^


$(ROOT_DIR)/$(VECTOR_LIB): $(VECTOR_OBJ)
	ar rcs $@ $^


$(ROOT_DIR)/$(MATH_LIB): $(MATH_OBJ)
	ar rcs $@ $^


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


.PHONY: clean
clean:
	rm -rf $(ROOT_DIR)/obj


.PHONY: fclean
fclean:
	rm -rf $(BUILD_DIR)
	rm -f $(CORE_LIB) $(ALLOC_LIB) $(VECTOR_LIB) $(PRINTF_LIB) $(MATH_LIB)


.PHONY: re
re: fclean
	@make all --no-print-directory


-include $(CORE_DEP) $(ALLOC_DEP) $(VECTOR_DEP) $(PRINTF_DEP) $(MATH_DEP)


TESTS=$(shell find tests -name "*.zig")


.PHONY: test
test:
	@for t in $(TESTS); do \
		echo "Running $$t..."; \
		$(ZIG) test $$t $(INCLUDES) -lc -L. -lftcore -lftalloc -lftvector \
		-lftprintf -lftmath || exit 1; \
	done


.PHONY: norm
norm:
	echo $(ALL_SRC) | xargs -n1 -P$(NPROC) norminette


.PHONY: tidy
tidy:
	echo $(ALL_SRC) | xargs -n1 -P$(NPROC) clang-tidy -p .
