/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:47:21 by net-touz          #+#    #+#             */
/*   Updated: 2022/05/15 11:47:45 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, int i)
{
	int	j;

	j = -1;
	while (++j < i)
		free(map[j]);
	free(map);
}

int	read_to_map(char *map, char ***to)
{
	int		fd;
	char	tmp;
	int		i;

	fd = ((i = 0), open(map, O_RDONLY));
	if (fd == -1)
		return (0);
	while (read(fd, &tmp, 1) > 0)
	{
		if (tmp == '\n')
		{
			i++;
			*to = (char **)ft_realloc(*to, sizeof(char *) * (i + 1));
			if (!*to)
				return (0);
			(*to)[i] = (char *)malloc(sizeof(char));
			if (!(*to)[i])
				return (0);
			(*to)[i][0] = '\0';
		}
		else
			(*to)[i] = ft_addchar((*to)[i], tmp);
	}
	i++;
	return (close(fd), i);
}
