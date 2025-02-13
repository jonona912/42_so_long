/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:32:59 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/02/13 17:33:32 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	connect_xpm_files(t_game_lst *g_lst)
{
	g_lst->imgs.player.path = "./textures/character.xpm";
	g_lst->imgs.clc.path = "./textures/tree_128.xpm";
	g_lst->imgs.exit.path = "./textures/home.xpm";
	g_lst->imgs.space.path = "./textures/dark_green.xpm";
	g_lst->imgs.wall.path = "./textures/rocks_128.xpm";
	connect_xpm_files_helper(&(g_lst->imgs.player), g_lst);
	connect_xpm_files_helper(&(g_lst->imgs.clc), g_lst);
	connect_xpm_files_helper(&(g_lst->imgs.exit), g_lst);
	connect_xpm_files_helper(&(g_lst->imgs.space), g_lst);
	connect_xpm_files_helper(&(g_lst->imgs.wall), g_lst);
}

int	draw_map_helper(t_game_lst *g_lst, int i, int y)
{
	int		j;
	int		x;
	void	*mlx;
	void	*win;

	mlx = g_lst->mlx;
	win = g_lst->win;
	x = 0;
	j = 0;
	while (*(*(g_lst->map + i) + j) && *(*(g_lst->map + i) + j) != '\n')
	{
		if (*(*(g_lst->map + i) + j) == 'P')
			mlx_put_image_to_window(mlx, win, g_lst->imgs.player.img, x, y);
		else if (*(*(g_lst->map + i) + j) == 'E')
			mlx_put_image_to_window(mlx, win, g_lst->imgs.exit.img, x, y);
		else if (*(*(g_lst->map + i) + j) == 'C')
			mlx_put_image_to_window(mlx, win, g_lst->imgs.clc.img, x, y);
		else if (*(*(g_lst->map + i) + j) == '0')
			mlx_put_image_to_window(mlx, win, g_lst->imgs.space.img, x, y);
		else if (*(*(g_lst->map + i) + j) == '1')
			mlx_put_image_to_window(mlx, win, g_lst->imgs.wall.img, x, y);
		x += g_lst->imgs.player.width;
		j++;
	}
	return (1);
}

int	draw_map(t_game_lst *g_lst)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (*(g_lst->map + i))
	{
		draw_map_helper(g_lst, i, y);
		y += g_lst->imgs.player.height;
		i++;
	}
	return (1);
}
