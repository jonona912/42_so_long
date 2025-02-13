/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:47:15 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/02/13 17:14:59 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	sl_free_game_mem(t_game_lst *g_lst, is_image status)
{
	if (status == IS_IMAGE)
	{
		mlx_destroy_image(g_lst->mlx, g_lst->imgs.clc.img);
		mlx_destroy_image(g_lst->mlx, g_lst->imgs.player.img);
		mlx_destroy_image(g_lst->mlx, g_lst->imgs.exit.img);
		mlx_destroy_image(g_lst->mlx, g_lst->imgs.space.img);
		mlx_destroy_image(g_lst->mlx, g_lst->imgs.wall.img);
	}
	sl_free_double_str(&(g_lst->map));
	mlx_destroy_window(g_lst->mlx, g_lst->win);
	mlx_destroy_display(g_lst->mlx);
	free(g_lst->mlx);
}

void	sl_free_double_str(char ***str)
{
	int	i;

	i = 0;
	while (*(*str + i))
	{
		free(*(*str + i));
		i++;
	}
	free(*str);
}
