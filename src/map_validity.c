/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:33:20 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/02/13 19:26:27 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	sl_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str && *str != '\n')
	{
		str++;
		i++;
	}
	return (i);
}

void	sl_free_str_lst(t_sl_lst **lst_map, char *line)
{
	free(line);
	sl_lst_clear(lst_map);
}

void	create_map_list(t_sl_lst **lst_map, int fd)
{
	int			init_len;
	char		*line;
	t_sl_lst	*node;

	line = get_next_line(fd);
	if (!line)
		sl_map_error("Couldn't read file or file is empty\n", 3);
	init_len = sl_strlen(line);
	while (line)
	{
		node = sl_new_node(line);
		if (!node)
		{
			sl_free_str_lst(lst_map, line);
			sl_map_error("Failed to create node\n", 1);
		}
		sl_lst_add_back(lst_map, node);
		line = get_next_line(fd);
		if (line && (init_len != sl_strlen(line)))
		{
			sl_free_str_lst(lst_map, line);
			sl_map_error("Not rectangle\n", 2);
		}
	}
}

int	sl_count_char(char	*str, int c)
{
	int	ctr;

	ctr = 0;
	while (*str)
	{
		if (*str == c)
			ctr++;
		str++;
	}
	if (*str == c)
		ctr++;
	return (ctr);
}

char	**is_map_valid(char *map)
{
	int			fd;
	t_sl_lst	*lst_map;
	char		**map_arr;
	int			collectible;

	lst_map = NULL;
	fd = open(map, O_RDONLY);
	create_map_list(&lst_map, fd);
	check_char_set(&lst_map);
	check_for_wall(&lst_map);
	sl_check_pos(&lst_map);
	collectible = lst_count_chars(&lst_map, 'C');
	if (collectible < 1)
	{
		sl_lst_clear(&lst_map);
		sl_map_error("No Collectible\n", 7);
	}
	map_arr = sl_convert_lst_str(&lst_map);
	check_map_path(&map_arr, collectible);
	return (map_arr);
}
