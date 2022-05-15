/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 09:56:14 by net-touz          #+#    #+#             */
/*   Updated: 2022/05/15 11:46:15 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_extention(char *map)
{
	if (ft_strrchr(map, '.'))
		if (ft_strcmp(".ber", ft_strrchr(map, '.')))
			return (0);
	return (1);
}

int	check_elements(t_mlx *mlx, char **map)
{
	int		i;
	int		j;
	int		c;
	int		e;
	int		p;

	i = ((c = 0, e = 0, p = 0), 0);
	while (i < mlx->assets->map_height)
	{
		j = 0;
		while (j < mlx->assets->map_width)
		{
			if (map[i][j] == 'C')
				c++;
			if (map[i][j] == 'E')
				e++;
			if (map[i][j] == 'P')
				p++;
			j++;
		}
		i++;
	}
	if (c < 1 || e < 1 || p != 1)
		return (0);
	return (1);
}

int	check_validity(t_mlx *mlx, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->assets->map_height)
	{
		j = 0;
		while (j < mlx->assets->map_width)
		{
			if (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'C' ||
					map[i][j] == 'E' || map[i][j] == 'P' || map[i][j] == 'N')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_borders(t_mlx *mlx, char **map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < mlx->assets->map_height)
	{
		j = 0;
		while (j < mlx->assets->map_width)
		{
			if (i == 0 || i == mlx->assets->map_height - 1 || j == 0
				|| j == mlx->assets->map_width - 1)
			{
				if (map[i][j] != '1')
					return (0);
			}
			j++;
		}
	}
	i = -1;
	while (++i < mlx->assets->map_height)
	{
		if ((int)ft_strlen(map[i]) != mlx->assets->map_width)
			return (0);
	}
	return (1);
}

int	validate_map(char *map, t_mlx *mlx)
{
	int		i;
	char	**_map;

	if (!check_extention(map))
		return (0);
	i = 0;
	_map = (char **)malloc(sizeof(char *));
	if (!_map)
		return (0);
	_map[i] = (char *)malloc(sizeof(char));
	if (!_map[i])
		return (free(_map), 0);
	_map[i][0] = '\0';
	i = read_to_map(map, &_map);
	if (i < 3)
		return (free_map(_map, i), 0);
	mlx->assets = (t_assets *)malloc(sizeof(t_assets));
	mlx->assets->map_height = i;
	mlx->assets->map_width = ft_strlen(_map[0]);
	if (mlx->assets->map_width < 3 || !check_validity(mlx, _map))
		return (free_map(_map, i), 0);
	if (!check_borders(mlx, _map) || !check_elements(mlx, _map))
		return (free_map(_map, i), 0);
	mlx->assets->map = _map;
	return (1);
}
