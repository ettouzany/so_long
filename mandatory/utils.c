/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 10:20:44 by net-touz          #+#    #+#             */
/*   Updated: 2022/05/14 22:35:35 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	put_img(t_mlx mlx, char *path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx.mlx, path, &img.width, &img.height);
	return (img);
}

void	mlx_img_put(t_mlx *mlx, t_img img, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, x, y);
}

int	load_assets(t_mlx *mlx)
{
	mlx->assets->wall = put_img(*mlx, "assets/wall.xpm");
	mlx->assets->coin = put_img(*mlx, "assets/coin.xpm");
	mlx->assets->player = put_img(*mlx, "assets/player.xpm");
	mlx->assets->door_open = put_img(*mlx, "assets/door_open.xpm");
	mlx->assets->door_closed = put_img(*mlx, "assets/door_closed.xpm");
	mlx->assets->coin_count = 0;
	mlx->assets->move_count = 0;
	return (0);
}

void	open_close(t_assets *a)
{
	int	i;
	int	j;

	i = -1;
	while (++i < a->map_height)
	{
		if (ft_strrchr(a->map[i], 'C') != NULL)
			return ;
	}
	i = -1;
	while (++i < a->map_height)
	{
		j = -1;
		while (++j < a->map_width)
		{
			if (a->map[i][j] == 'E')
				a->map[i][j] = 'O';
		}
	}
}

int	render_assets(t_mlx *m)
{
	int			i;
	int			j;

	i = -1;
	while (++i < m->assets->map_height)
	{
		j = 0;
		while (j < m->assets->map_width)
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
				mlx_img_put(m, m->assets->door_closed, j * 56, i * 56);
			j++;
		}
	}
	return (0);
}
