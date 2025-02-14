/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:43:56 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/02/14 13:33:52 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	traverse_map_path(char **map, int r, int c, t_c_count *chars)
{
	if (*(*(map + r) + c) == 'E')
	{
		(*chars).ext++;
		*(*(map + r) + c) = '1';
	}
	if (*(*(map + r) + c) == '0' || (*(*(map + r) + c) == 'P')
		|| (*(*(map + r) + c) == 'C'))
	{
		if (*(*(map + r) + c) == 'P')
			(*chars).pos++;
		else if (*(*(map + r) + c) == 'E')
			(*chars).ext++;
		else if (*(*(map + r) + c) == 'C')
			(*chars).clc++;
		*(*(map + r) + c) = '1';
		traverse_map_path(map, r - 1, c, chars);
		traverse_map_path(map, r + 1, c, chars);
		traverse_map_path(map, r, c - 1, chars);
		traverse_map_path(map, r, c + 1, chars);
	}
}

int	find_position(char **map, int *r, int *c)
{
	int	i;
	int	j;

	i = 0;
	while (*(map + i))
	{
		j = 0;
		while (*(*(map + i) + j))
		{
			if (*(*(map + i) + j) == 'P')
			{
				*r = i;
				*c = j;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	sl_str_double_len(char **str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

char	**sl_strdup_double(char **str)
{
	int		str_len;
	char	**str_cp;
	int		i;

	str_len = sl_str_double_len(str);
	str_cp = (char **)malloc(sizeof(char *) * (str_len + 1));
	if (!str_cp)
		return (NULL);
	i = 0;
	while (*(str + i))
	{
		*(str_cp + i) = ft_strdup(*(str + i));
		if (!*(str_cp + i))
		{
			sl_free_double_str(&str_cp);
			sl_map_error("Malloc failure\n", 3);
		}
		i++;
	}
	*(str_cp + i) = NULL;
	return (str_cp);
}

int	check_map_path(char ***map, int collectible)
{
	int			r;
	int			c;
	t_c_count	map_chars;
	char		**map_cp;

	map_chars.clc = 0;
	map_chars.ext = 0;
	map_chars.pos = 0;
	map_cp = sl_strdup_double(*map);
	find_position(*map, &r, &c);
	traverse_map_path(map_cp, r, c, &map_chars);
	sl_free_double_str(&map_cp);
	if (map_chars.clc != collectible)
	{
		sl_free_double_str(map);
		sl_map_error("Collectible not reachable\n", 9);
	}
}
