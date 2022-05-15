/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:35:21 by net-touz          #+#    #+#             */
/*   Updated: 2022/05/15 11:45:51 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	mlx->assets->enemy_1 = put_img(*mlx, "assets/enemy1.xpm");
	mlx->assets->enemy_2 = put_img(*mlx, "assets/enemy2.xpm");
	mlx->assets->coin_count = 0;
	mlx->assets->move_count = 0;
	return (0);
}

int	ckeck_enemies(t_assets *a)
{
	int	i;
	int	j;

	i = -1;
	while (++i < a->map_height)
	{
		j = -1;
		while (++j < a->map_width)
		{
			if (a->map[i][j] == 'N')
				a->map[i][j] = 'Y';
			else if (a->map[i][j] == 'Y')
				a->map[i][j] = 'N';
		}
	}
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
