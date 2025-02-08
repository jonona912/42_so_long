/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:35:34 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/02/04 23:13:02 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	sl_map_error(char *str, int n)
{
	ft_putstr_fd(str, 2);
	exit(n);
}

int	check_wall(char	*str)
{
	while (*str && *str != '\n')
	{
		if (*str != '1')
			return (0);
		str++;
	}
	return (1);
}

int	check_top_bottom_wall(t_sl_lst	*map_lst)
{
	t_sl_lst	*last;

	last = sl_lst_last(map_lst);
	if (!check_wall(map_lst->line) || !check_wall(last->line))
		return (0);
	return (1);
}

int	check_str_sides(char *str)
{
	int	len;

	len = sl_strlen(str);
	if (*str != '1' || str[len - 1] != '1')
		return (0);
	return (1);
}

int	check_for_wall(t_sl_lst	**map_lst)
{
	char		*str;
	int			is_wall;
	t_sl_lst	*tranverse;

	if (!check_top_bottom_wall(*map_lst))
	{
		sl_lst_clear(map_lst);
		sl_map_error("Invalid wall\n", 4);
	}
	tranverse = *map_lst;
	while (tranverse)
	{
		if (!check_str_sides(tranverse->line))
		{
			sl_lst_clear(map_lst);
			sl_map_error("Invalid wall\n", 4);
		}
		tranverse = tranverse->next;
	}
	return (1);
}
