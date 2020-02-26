#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
    int i;

    i = 0;
	while (!ft_memcmp(s1 + i, s2 + i, 1) && *(s1 + i))
		i += 1;
	return (ft_memcmp(s1 + i, s2 + i, 1));
}