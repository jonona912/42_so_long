SRC_DIR = src
OBJ_DIR = obj
FT_PRINTF_DIR = ft_printf
GNL_DIR = gnl
LIBFT_DIR = libft
MINILIBX_DIR = minilibx-linux


LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
GNL = $(GNL_DIR)/libgnl.a
MINILIBX = $(MINILIBX_DIR)/libmlx_Linux.a

LIBS = -L $(FT_PRINTF_DIR) -lftprintf -L $(GNL_DIR) -lgnl -L $(MINILIBX_DIR) -lmlx_Linux -lm -lX11 -lXext


NAME = so_long
CC = cc
CFLAGS = -g #-Wall -Wextra -Werror

SRCS = check_map_path.c \
		check_map_wall.c \
		create_window.c \
		main_so_long.c \
		map_validity.c \
		sl_lists.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF) $(GNL) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

# The -C option is used with make to change the directory before executing the Makefile.
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)
$(GNL):
	$(MAKE) -C $(GNL_DIR)
$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

# % is a wildcard that matches any string
# -p flag creates the directory if it doesn’t exist and doesn’t throw an error if it already exists.
# -c: This flag tells the compiler to compile the source file into an object file but not to link it into an executable.
# $<: This is an automatic variable that refers to the first prerequisite (in this case, the .c file, e.g., src/main.c).
# -o $@: This specifies the output file. $@ is another automatic variable that refers to the target (in this case, the .o file, e.g., obj/main.o).
# $<: Refers to the first prerequisite (the .c file, e.g., src/main.c).
# $@: Refers to the target (the .o file, e.g., obj/main.o).

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	cd $(LIBFT_DIR) && $(MAKE) clean
	cd $(GNL_DIR) && $(MAKE) clean
	cd $(FT_PRINTF_DIR) && $(MAKE) clean
	cd $(MINILIBX_DIR) && $(MAKE) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	cd $(LIBFT_DIR) && $(MAKE) fclean
	cd $(GNL_DIR) && $(MAKE) fclean
	cd $(FT_PRINTF_DIR) && $(MAKE) fclean

#Libraries
re: fclean all

