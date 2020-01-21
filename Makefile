CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -I$(HEADERS_DIR)
NAME			= cub3D
SRCS_DIR		= srcs
SRCS_FILES		= main.c map.c render.c key.c textures.c dda.c utils_1.c utils_2.c
SRCS			= $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS_DIR		= objs
OBJS_FILES		= $(SRCS_FILES:.c=.o)
OBJS			= $(addprefix $(OBJS_DIR)/, $(OBJS_FILES))
HEADERS_DIR		= includes
HEADERS_FILES	= map.h cub3d.h player.h render.h get_next_line.h
HEADERS			= $(addprefix $(HEADERS_DIR)/, $(HEADERS_FILES))
LIBRAIRIES		= -lmlx -framework OpenGL -framework AppKit
SRCS_PARSE		= $(SRCS_DIR)/error.c $(SRCS_DIR)/get_next_line.c $(SRCS_DIR)/get_next_line_utils.c $(SRCS_DIR)/utils_1.c $(SRCS_DIR)/utils_2.c $(SRCS_DIR)/utils_3.c $(SRCS_DIR)/parser_tex.c $(SRCS_DIR)/parser_tex_utils.c $(SRCS_DIR)/parser_rfc.c $(SRCS_DIR)/test_parser.c

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

testparser:
	$(CC) -I$(HEADERS_DIR) $(SRCS_PARSE) -o parser.out

re: fclean all

.PHONY: all clean fclean re