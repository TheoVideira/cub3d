#include "parser.h"

void	create_line_map(char *line, t_game_info *gi, int n)
{
	char	**split;
	int		len;
	int		i;	

	i = -1;
	len = 0;
	split = ft_split(line, ' ');
	while (split[++i])
		len += ft_strlen(split[i]);
	if (!(gi->map[n] = ft_calloc(1, sizeof(char) * len + 1)))
	{
		ft_emergency_split(split);
		ft_emergency_split(gi->map);
		ft_error_free("error during calloc\n", gi);
	}
	i = -1;
	while(split[++i])
		ft_strlcat(gi->map[n], split[i], len + 1);
	ft_emergency_split(split);
}