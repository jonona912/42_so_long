/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:33:06 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/02/13 17:36:25 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	sl_map_dimensions(char **map, int *height, int *width)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	while (*((*map) + w))
		w++;
	while (*(map + h))
		h++;
	*height = h;
	*width = w - 1;
}

t_game_lst	sl_crt_win(t_game_lst *g_lst)
{
	int	height;
	int	width;

	sl_map_dimensions(g_lst->map, &height, &width);
	height *= HEIGHT;
	width *= WIDTH;
	g_lst->mlx = mlx_init();
	if (!(g_lst->mlx))
	{
		sl_free_double_str(&(g_lst->map));
		sl_map_error("Could not initialize mlx\n", 10);
	}
	g_lst->win = mlx_new_window(g_lst->mlx, width, height, "Hezoom");
	if (!(g_lst->win))
	{
		sl_free_double_str(&(g_lst->map));
		mlx_destroy_display(g_lst->mlx);
		free(g_lst->mlx);
		sl_map_error("Could not crete a window\n", 11);
	}
	return (*g_lst);
}

void	connect_xpm_files_helper(t_img_sl *imgs, t_game_lst *g_lst)
{
	int	h;
	int	w;

	imgs->img = mlx_xpm_file_to_image(g_lst->mlx, imgs->path, &w, &h);
	if (!(imgs->img))
	{
		sl_free_game_mem(g_lst, NO_IMAGE);
		sl_map_error("Could not find images\n", 11);
	}
	imgs->width = w;
	imgs->height = h;
}
