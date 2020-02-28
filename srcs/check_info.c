#include "parser.h"
#include <stdio.h>

void    check_resolution(t_parse_info *pi, t_game_info *gi)
{
    if (pi->r == 0)
        ft_error_free("Missing resolution\n", gi);
    if (pi->r != 1)
        ft_error_free("Resolution appeared mutliple times\n", gi);
    if (gi->resolution[0] == -1)
        ft_error_free("Resolution x parameter didn't appeared\n", gi);
    if (gi->resolution[0] == -2)
        ft_error_free("Resolution x parameter is invalid\n", gi);
    if (gi->resolution[0] == -3)
        ft_error_free("Separator before x resolution parameter is invalid\n"\
        , gi);
    if (gi->resolution[1] == -1)
        ft_error_free("Resolution y parameter didn't appeared\n", gi);
    if (gi->resolution[1] == -2)
        ft_error_free("Resolution y parameter is invalid\n", gi);
    if (gi->resolution[1] == -3)
        ft_error_free("Separator before y resolution parameter is invalid\n"\
        , gi);
    if (gi->resolution[1] == -4)
        ft_error_free("Resolution isn't ended just after y parameter\n", gi);
}

void    check_f_color(t_parse_info *pi, t_game_info *gi)
{
    if (pi->f == 0)
        ft_error_free("Missing floor color\n", gi);
    if (pi->f != 1)
        ft_error_free("Floor color appeared mutliple times\n", gi);
    if (gi->f_color[0] == -1)
        ft_error_free("Floor red color parameter didn't appeared\n", gi);
    if (gi->f_color[0] == -2)
        ft_error_free("Floor red color parameter is invalid\n", gi);
    if (gi->f_color[0] == -3)
        ft_error_free("Separator before floor red color is invalid\n", gi);
    if (gi->f_color[1] == -1)
        ft_error_free("Floor blue color parameter didn't appeared\n", gi);
    if (gi->f_color[1] == -2)
        ft_error_free("Floor blue color parameter is invalid\n", gi);
    if (gi->f_color[1] == -3)
        ft_error_free("Separator before floor blue color is invalid\n", gi);
    if (gi->f_color[2] == -1)
        ft_error_free("Floor green color parameter didn't appeared\n", gi);
    if (gi->f_color[2] == -2)
        ft_error_free("Floor green color parameter is invalid\n", gi);
    if (gi->f_color[2] == -3)
        ft_error_free("Separator before floor green color is invalid\n", gi);
    if (gi->f_color[2] == -4)
        ft_error_free("Floor color isn't ended just after green parameter\n"\
        , gi);
}

void    check_c_color(t_parse_info *pi, t_game_info *gi)
{
    if (pi->c == 0)
        ft_error_free("Missing ceil color\n", gi);
    if (pi->c != 1)
        ft_error_free("Ceil color appeared mutliple times\n", gi);
    if (gi->c_color[0] == -1)
        ft_error_free("Ceil red color parameter didn't appeared\n", gi);
    if (gi->c_color[0] == -2)
        ft_error_free("Ceil red color parameter is invalid\n", gi);
    if (gi->c_color[0] == -3)
        ft_error_free("Separator before ceil red color is invalid\n", gi);
    if (gi->c_color[1] == -1)
        ft_error_free("Ceil blue color parameter didn't appeared\n", gi);
    if (gi->c_color[1] == -2)
        ft_error_free("Ceil blue color parameter is invalid\n", gi);
    if (gi->c_color[1] == -3)
        ft_error_free("Separator before ceil blue color is invalid\n", gi);
    if (gi->c_color[2] == -1)
        ft_error_free("Ceil green color parameter didn't appeared\n", gi);
    if (gi->c_color[2] == -2)
        ft_error_free("Ceil green color parameter is invalid\n", gi);
    if (gi->c_color[2] == -3)
        ft_error_free("Separator before ceil green color is invalid\n", gi);
    if (gi->c_color[2] == -4)
        ft_error_free("Ceil color isn't ended just after green parameter\n"\
        , gi);
}

int     check_format(char *filename, char *format)
{
    int     i;
    int     j;
    char    *x;

    x = ft_strrchr(filename, '.');
    if (!x || !format)
        return (1);
    i = ft_strlen(x);
    j = ft_strlen(format);
    return (ft_strncmp(format, x, ft_max(i, j)));
}