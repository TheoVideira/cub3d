#include "parser.h"

void	check_no_tex(t_parse_info *pi, t_game_info *gi)
{
	int fd;

	if (pi->no == 0)
		ft_error_free("Missing north texture\n", gi);
	if (pi->no != 1)
		ft_error_free("North texture appeared mutliple times\n", gi);
	fd = open(gi->texture.path[0], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nNorth texture : ", 22);
		ft_error_no_free(errno, gi);
	}
	if (check_format(gi->texture.path[0], ".xpm"))
	{
		close(fd);
		ft_error_free("North texture file isn't a .xpm file\n", gi);
	}
	close(fd);
}

void	check_so_tex(t_parse_info *pi, t_game_info *gi)
{
	int fd;

	if (pi->so == 0)
		ft_error_free("Missing south texture\n", gi);
	if (pi->so != 1)
		ft_error_free("South texture appeared mutliple times\n", gi);
	fd = open(gi->texture.path[1], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nSouth texture : ", 22);
		ft_error_no_free(errno, gi);
	}
	if (check_format(gi->texture.path[1], ".xpm"))
	{
		close(fd);
		ft_error_free("South texture file isn't a .xpm file\n", gi);
	}
	close(fd);
}

void	check_ea_tex(t_parse_info *pi, t_game_info *gi)
{
	int fd;

	if (pi->ea == 0)
		ft_error_free("Missing ea texture\n", gi);
	if (pi->ea != 1)
		ft_error_free("East texture appeared mutliple times\n", gi);
	fd = open(gi->texture.path[2], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nEast texture : ", 21);
		ft_error_no_free(errno, gi);
	}
	if (check_format(gi->texture.path[2], ".xpm"))
	{
		close(fd);
		ft_error_free("East texture file isn't a .xpm file\n", gi);
	}
	close(fd);
}

void	check_we_tex(t_parse_info *pi, t_game_info *gi)
{
	int fd;

	if (pi->we == 0)
		ft_error_free("Missing west texture\n", gi);
	if (pi->we != 1)
		ft_error_free("West texture appeared mutliple times\n", gi);
	fd = open(gi->texture.path[3], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nWest texture : ", 21);
		ft_error_no_free(errno, gi);
	}
	if (check_format(gi->texture.path[3], ".xpm"))
	{
		close(fd);
		ft_error_free("West texture file isn't a .xpm file\n", gi);
	}
	close(fd);
}

void	check_sp_tex(t_parse_info *pi, t_game_info *gi)
{
	int fd;

	if (pi->s == 0)
		ft_error_free("Missing sprite texture\n", gi);
	if (pi->s != 1)
		ft_error_free("Sprite texture appeared mutliple times\n", gi);
	fd = open(gi->texture.path[4], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nSprite texture : ", 23);
		ft_error_no_free(errno, gi);
	}
	if (check_format(gi->texture.path[4], ".xpm"))
	{
		close(fd);
		ft_error_free("Sprite texture file isn't a .xpm file\n", gi);
	}
	close(fd);
}