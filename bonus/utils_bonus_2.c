/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:53:32 by net-touz          #+#    #+#             */
/*   Updated: 2022/05/15 11:46:27 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_assets(t_mlx *m)
{
	int			i;
	int			j;

	i = -1;
	while (++i < m->assets->map_height)
	{
		j = -1;
		while (++j < m->assets->map_width)
		{
			if (m->assets->map[i][j] == '1')
				mlx_img_put(m, m->assets->wall, j * 56, i * 56);
			else if (m->assets->map[i][j] == 'C')
				mlx_img_put(m, m->assets->coin, j * 56, i * 56);
			else if (m->assets->map[i][j] == 'P')
				mlx_img_put(m, m->assets->player, j * 56, i * 56);
			else if (m->assets->map[i][j] == 'O')
				mlx_img_put(m, m->assets->door_open, j * 56, i * 56);
			else if (m->assets->map[i][j] == 'E')
				mlx_img_put(m, m->assets->door_closed, j * 56, i * 56);
			else if (m->assets->map[i][j] == 'N')
				mlx_img_put(m, m->assets->enemy_1, j * 56, i * 56);
			else if (m->assets->map[i][j] == 'Y')
				mlx_img_put(m, m->assets->enemy_2, j * 56, i * 56);
		}
	}
}

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
