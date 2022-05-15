/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: net-touz <net-touz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 09:46:49 by net-touz          #+#    #+#             */
/*   Updated: 2022/05/15 12:21:46 by net-touz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct t_img
{
	void	*img;
	int		height;
	int		width;
}	t_img;

typedef struct t_assets
{
	t_img	wall;
	t_img	coin;
	t_img	player;
	t_img	door_open;
	t_img	door_closed;
	int		coin_count;
	int		move_count;
	char	**map;
	int		map_height;
	int		map_width;
}	t_assets;

typedef struct t_mlx
{
	void		*mlx;
	void		*win;
	t_assets	*assets;
}	t_mlx;

int		validate_map(char *map, t_mlx *mlx);
int		load_assets(t_mlx *mlx);
t_img	put_img(t_mlx mlx, char *path);
int		render_assets(t_mlx *mlx);
int		close_window(t_mlx *mlx);
void	open_close(t_assets *a);
int		read_to_map(char *map, char ***to);
void	free_map(char **map, int i);
#endif