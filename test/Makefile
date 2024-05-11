
NAME = libminirt.a

SRC_DIR := .

SRCS := \

SRCS := $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR   := .build

OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)

CC = gcc
DIR_DUP = mkdir -p $(@D)
CLEANER = rm -rf

AR := ar
ARFLAGS  := -r -c -s

CCFLAGS = -Wall -Werror -Wextra

all: $(NAME) test run fclean

test:
	@$(CC) -I.. munit.c minirt_test.c -o test_minirt -L. -lminirt

run:
	./test_minirt

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(DIR_DUP)
	@$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@$(CLEANER) $(OBJS)

fclean: clean
	@$(CLEANER) .build
	@$(CLEANER) test_minirt
	@$(CLEANER) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all