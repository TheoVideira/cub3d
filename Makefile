CC				= gcc

CFLAGS			= -Wall -Wextra -Werror $(INCLUDES)
MLX_FLAGS		= -lmlx -framework OpenGL -framework AppKit
LIBRARIES		= libft/libft.a gnl/gnl.a
INCLUDES_FOLDER	= gnl includes libft
INCLUDES		= $(addprefix -I, $(INCLUDES_FOLDER))

NAME			= cub3D

SRCS_DIR		= srcs
SRCS_FILES		= main.c map.c render.c key.c textures.c dda.c # utils_1.c utils_2.c
SRCS			= $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS_DIR		= objs
OBJS_FILES		= $(SRCS_FILES:.c=.o)
OBJS			= $(addprefix $(OBJS_DIR)/, $(OBJS_FILES))

HEADERS_FILES	= map.h cub3d.h player.h render.h get_next_line.h

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(MAKE) -C gnl
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(LIBRARIES) -o $(NAME)

debug:
	$(CC) $(CFLAGS) -g3 -fsanitize=address $(MLX_FLAGS) $(OBJS) -o $(NAME)	

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
	$(CC) $(CFLAGS) srcs/parser*.c srcs/*check*.c srcs/error.c srcs/init_struct.c $(LIBRARIES)

re: fclean all

.PHONY: all clean fclean re
