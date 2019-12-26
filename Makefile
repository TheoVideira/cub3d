CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
NAME			= cub3D
SRCS_DIR		= srcs
SRCS_FILES		= main.c map.c render.c key.c textures.c
SRCS			= $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS_DIR		= objs
OBJS_FILES		= $(SRCS_FILES:.c=.o)
OBJS			= $(addprefix $(OBJS_DIR)/, $(OBJS_FILES))
HEADERS_FILES	= map.h cub3d.h player.h render.h
HEADERS			= $(addprefix $(SRCS_DIR)/, $(HEADERS_FILES))
LIBRAIRIES		= -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

debug:
	$(CC) $(CFLAGS) -g3 -fsanitize=address $(LIBRAIRIES) $(OBJS) -o $(NAME)	

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LIBRAIRIES) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re