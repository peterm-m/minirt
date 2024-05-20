
NAME = libarray.a

SRC_DIR := .

SRCS := \
	expand_capacity.c \
	ft_array_add.c \
	ft_array_add_at.c \
	ft_array_capacity.c \
	ft_array_conf_init.c \
	ft_array_contains.c \
	ft_array_contains_value.c \
	ft_array_copy_deep.c \
	ft_array_copy_shallow.c \
	ft_array_destroy.c \
	ft_array_destroy_cb.c \
	ft_array_filter.c \
	ft_array_filter_mut.c \
	ft_array_get_at.c \
	ft_array_get_buffer.c \
	ft_array_get_last.c \
	ft_array_index_of.c \
	ft_array_iter_add.c \
	ft_array_iter_index.c \
	ft_array_iter_init.c \
	ft_array_iter_next.c \
	ft_array_iter_remove.c \
	ft_array_iter_replace.c \
	ft_array_map.c \
	ft_array_new.c \
	ft_array_new_conf.c \
	ft_array_reduce.c \
	ft_array_remove.c \
	ft_array_remove_all.c \
	ft_array_remove_all_free.c \
	ft_array_remove_at.c \
	ft_array_remove_last.c \
	ft_array_replace_at.c \
	ft_array_reverse.c \
	ft_array_size.c \
	ft_array_sort.c \
	ft_array_subarray.c \
	ft_array_swap_at.c \
	ft_array_trim_capacity.c \
	ft_array_zip_add.c \
	ft_array_zip_index.c \
	ft_array_zip_init.c \
	ft_array_zip_next.c \
	ft_array_zip_remove.c \
	ft_array_zip_replace.c \

SRCS := $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR := .build

OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

CC = gcc
DIR_DUP = mkdir -p $(@D)
CLEANER = rm -rf

AR := ar
ARFLAGS  := -r -c -s

CCFLAGS = -Wall -Werror -Wextra 

all:$(NAME) 

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(info CREATED $(NAME))

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CCFLAGS) -c $< -o $@
	$(info CREATED $@)

clean:
	$(CLEANER) $(BUILD_DIR)

fclean: clean 
	$(CLEANER) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

tests:
	@make -C .test
