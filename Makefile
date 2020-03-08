CC				= gcc

CFLAGS			= -Wall -Wextra -Werror $(INCLUDES)
MLX_FLAGS		= -lmlx -framework OpenGL -framework AppKit
MLX_WSL_FLAGS	= -L/usr/local/lib -lmlx -lm -lXext -lX11 -lpthread -lxcb -lXau -lXdmcp -lbsd
LIBRARIES		= libft/libft.a gnl/gnl.a
INCLUDES_FOLDER	= gnl includes libft
INCLUDES		= $(addprefix -I, $(INCLUDES_FOLDER))

NAME			= cub3D

SRCS_DIR		= srcs
SRCS_FILES		= check.c check_texture.c dda.c first_check_map.c init_struct.c main.c parser_col.c parser_res.c render.c\
				  check_info.c closed_map_utils.c error.c get_map_utils.c key.c parser.c parser_map.c parser_tex.c textures.c\
				  render_sprite.c
SRCS			= $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS_DIR		= objs
OBJS_FILES		= $(SRCS_FILES:.c=.o)
OBJS			= $(addprefix $(OBJS_DIR)/, $(OBJS_FILES))

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(MAKE) -C gnl
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(LIBRARIES) -o $(NAME)

wsl: $(OBJS)
	$(MAKE) -C libft
	$(MAKE) -C gnl
	$(CC) $(CFLAGS) $(OBJS) $(LIBRARIES) -o $(NAME) $(MLX_WSL_FLAGS)


debug:
	$(CC) $(CFLAGS) -g3 -fsanitize=address $(MLX_FLAGS) $(OBJS) $(LIBRARIES) -o $(NAME)

debug_wsl:
	$(CC) $(CFLAGS) -g3 -fsanitize=address $(OBJS) $(LIBRARIES) -o $(NAME) $(MLX_WSL_FLAGS)

#Create .o folder
$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

#Compile .o
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C gnl clean
	rm -rf $(OBJS)
	rm -rf $(OBJS_DIR)

fclean: clean
	$(MAKE) -C libft fclean
	$(MAKE) -C gnl fclean
	rm -f $(NAME)

testparser:
	$(CC) $(CFLAGS) srcs/parser*.c srcs/*check*.c srcs/error.c srcs/init_struct.c srcs/get_map_utils.c srcs/closed_map_utils.c $(LIBRARIES)

re: fclean all

.PHONY: all clean fclean re
