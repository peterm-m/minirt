
NAME = libdlst.a

SRC_DIR := .

SRCS = ../ft_dlst_add_all_at.c \
	../ft_dlst_add_all.c \
	../ft_dlst_add_at.c \
	../ft_dlst_add.c \
	../ft_dlst_add_first.c \
	../ft_dlst_add_last.c \
	../ft_dlst_conf_init.c \
	../ft_dlst_contains.c \
	../ft_dlst_contains_value.c \
	../ft_dlst_copy_deep.c \
	../ft_dlst_copy_shallow.c \
	../ft_dlst_destroy.c \
	../ft_dlst_destroy_cb.c \
	../ft_dlst_diter_add.c \
	../ft_dlst_diter_index.c \
	../ft_dlst_diter_init.c \
	../ft_dlst_diter_next.c \
	../ft_dlst_diter_remove.c \
	../ft_dlst_diter_replace.c \
	../ft_dlst_filter.c \
	../ft_dlst_filter_mut.c \
	../ft_dlst_foreach.c \
	../ft_dlst_get_at.c \
	../ft_dlst_get_first.c \
	../ft_dlst_get_last.c \
	../ft_dlst_index_of.c \
	../ft_dlst_iter_add.c \
	../ft_dlst_iter_index.c \
	../ft_dlst_iter_init.c \
	../ft_dlst_iter_next.c \
	../ft_dlst_iter_remove.c \
	../ft_dlst_iter_replace.c \
	../ft_dlst_new.c \
	../ft_dlst_new_conf.c \
	../ft_dlst_reduce.c \
	../ft_dlst_remove_all.c \
	../ft_dlst_remove_all_cb.c \
	../ft_dlst_remove_at.c \
	../ft_dlst_remove.c \
	../ft_dlst_remove_first.c \
	../ft_dlst_remove_last.c \
	../ft_dlst_replace_at.c \
	../ft_dlst_reverse.c \
	../ft_dlst_size.c \
	../ft_dlst_sort.c \
	../ft_dlst_splice_at.c \
	../ft_dlst_splice.c \
	../ft_dlst_sublist.c \
	../ft_dlst_to_array.c \
	../ft_dlst_zip_add.c \
	../ft_dlst_zip_index.c \
	../ft_dlst_zip_init.c \
	../ft_dlst_zip_next.c \
	../ft_dlst_zip_remove.c \
	../ft_dlst_zip_replace.c \
	../link_behind.c \
	../link_after.c \
	../swap.c \
	../unlink.c \
	../unlink_all.c \
	../get_node_at.c \
	../get_node.c \
	../splice_between.c \
	../link_all_externally.c \
	../add_all_to_empty.c \
	../swap_adjacent.c \


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
	@$(CC) -I.. munit.c dlst_test.c -o test_dlst -L. -ldlst

run:
	./test_dlst

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(DIR_DUP)
	@$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@$(CLEANER) $(OBJS)

fclean: clean
	@$(CLEANER) .build
	@$(CLEANER) test_dlst
	@$(CLEANER) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
