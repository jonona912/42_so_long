/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:27:49 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/02/13 19:34:41 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	find_pos(t_game_lst *g_lst, int *x_pos, int *y_pos)
{
	int	x;
	int	y;

	y = 0;
	while (*(g_lst->map + y))
	{
		x = 0;
		while (*(*(g_lst->map + y) + x))
		{
			if (*(*(g_lst->map + y) + x) == 'P')
			{
				*x_pos = x;
				*y_pos = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

// int	is_mv_valid(t_game_lst *g_lst, int x_pos, int y_pos)
// {
// 	return (*(*(g_lst->map + y_pos) + x_pos) == '0'
// 		|| *(*(g_lst->map + y_pos) + x_pos) == 'C');
// }

void	set_positions(move_dir dir, int *x_pos, int *y_pos)
{
	if (dir == RIGHT)
		*x_pos += 1;
	else if (dir == LEFT)
		*x_pos -= 1;
	else if (dir == TOP)
		*y_pos -= 1;
	else if (dir == DOWN)
		*y_pos += 1;
}

int	make_move(t_game_lst *g_lst, move_dir dir)
{
	int	x_pos;
	int	y_pos;
	int	x_prev;
	int	y_prev;

	find_pos(g_lst, &x_pos, &y_pos);
	x_prev = x_pos;
	y_prev = y_pos;
	set_positions(dir, &x_pos, &y_pos);
	if (*(*(g_lst->map + y_pos) + x_pos) == 'E')
	{
		sl_free_game_mem(g_lst, IS_IMAGE);
		exit(0);
	}
	if (*(*(g_lst->map + y_pos) + x_pos) == '0'
		|| *(*(g_lst->map + y_pos) + x_pos) == 'C')
	{
		*(*(g_lst->map + y_prev) + x_prev) = '0';
		*(*(g_lst->map + y_pos) + x_pos) = 'P';
		return (1);
	}
	return (0);
}

int	sl_is_move(int key, t_game_lst *g_lst)
{
	return ((key == 97 && make_move(g_lst, LEFT))
		|| (key == 100 && make_move(g_lst, RIGHT))
		|| (key == 119 && make_move(g_lst, TOP))
		|| (key == 115 && make_move(g_lst, DOWN)));
}

int	key_response(int key, void *p)
{
	t_game_lst	*g_lst;

	g_lst = (t_game_lst *) p;
	if (sl_is_move(key, g_lst))
	{
		g_lst->mv_ctr++;
		ft_printf("Move Number %d\n", g_lst->mv_ctr);
		mlx_clear_window(g_lst->mlx, g_lst->win);
		draw_map(g_lst);
	}
	if (key == 0xFF1B)
	{
		sl_free_game_mem(g_lst, IS_IMAGE);
		exit(0);
	}
	return (1);
}
