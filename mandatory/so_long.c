/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 09:45:05 by net-touz          #+#    #+#             */
/*   Updated: 2022/05/15 12:21:50 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_assets *assets, int x, int y)
{
	int		i;
	int		j;

	i = -1;
	while (++i < assets->map_height)
	{
		j = -1;
		while (++j < assets->map_width)
		{
			if (assets->map[i][j] == 'P')
			{
				if (assets->map[i + y][j + x] == '0' ||
						assets->map[i + y][j + x] == 'C' ||
						assets->map[i + y][j + x] == 'O')
				{
					assets->map[i][j] = '0';
					assets->map[i + y][j + x] = 'P';
					assets->move_count++;
					ft_putnbr(assets->move_count);
					ft_putchar('\n');
				}
				return ;
			}
		}
	}
}

void	check_win(t_mlx *mlx)
{
	int		i;
	int		j;

	i = -1;
	while (++i < mlx->assets->map_height)
	{
		j = 0;
		while (j < mlx->assets->map_width)
		{
			if (mlx->assets->map[i][j] == 'E' || mlx->assets->map[i][j] == 'O')
				return ;
			j++;
		}
	}
	close_window(mlx);
}	

int	key_hook(int key, t_mlx *mlx)
{
	if (key == 53)
		close_window(mlx);
	else if (key == 1 || key == 2 || key == 13 || key == 0)
	{
		if (key == 1)
			move_player(mlx->assets, 0, 1);
		if (key == 13)
			move_player(mlx->assets, 0, -1);
		if (key == 0)
			move_player(mlx->assets, -1, 0);
		if (key == 2)
			move_player(mlx->assets, 1, 0);
		mlx_clear_window(mlx->mlx, mlx->win);
		open_close(mlx->assets);
		check_win(mlx);
		render_assets(mlx);
	}
	return (0);
}

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	while (mlx->assets->map_height--)
		free(mlx->assets->map[mlx->assets->map_height]);
	free(mlx->assets->map);
	free(mlx->assets->wall.img);
	free(mlx->assets->coin.img);
	free(mlx->assets->player.img);
	free(mlx->assets->door_closed.img);
	free(mlx->assets->door_open.img);
	free(mlx->assets);
	free(mlx->mlx);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
		return (ft_putstr("No Map\n"), 0);
	mlx.mlx = mlx_init();
	if (!validate_map(argv[1], &mlx))
		return (ft_putstr("map invalide\n"), 0);
	mlx.win = mlx_new_window(mlx.mlx, 56 * mlx.assets->map_width,
			56 * mlx.assets->map_height, "So_long");
	load_assets(&mlx);
	render_assets(&mlx);
	mlx_hook(mlx.win, 2, 0, key_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, close_window, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
