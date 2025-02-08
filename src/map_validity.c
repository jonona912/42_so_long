/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:33:20 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/02/06 10:37:06 by zkhojazo         ###   ########.fr       */
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

int	create_map_list(int	**lst_map, int fd)
{
	int			init_len;
	char		*line;
	t_sl_lst	*node;

	line = get_next_line(fd);
	if (!line)
		sl_map_error("Couldn't read file or file is empty\n", 3);
	init_len = sl_strlen(line);
	while(line)
	{
		node = sl_new_node(line);
		if (!node)
		{
			free(line);
			sl_lst_clear(lst_map);
			sl_map_error("Failed to create node\n", 1);
		}
		sl_lst_add_back(lst_map, node);
		line = get_next_line(fd);
		if (line && (init_len != sl_strlen(line)))
		{
			free(line);
			sl_lst_clear(lst_map);
			sl_map_error("Not rectangle\n", 2);
		}
	}
}

char	**sl_convert_lst_str(t_sl_lst **lst)
{
	int		lst_len;
	char	**ret;
	int		i;
	t_sl_lst	*temp_lst;

	i = 0;
	lst_len = sl_lst_len(*lst);
	ret = (char **)malloc(sizeof(char *) * (lst_len + 1));
	temp_lst = *lst;
	while (temp_lst)
	{
		*(ret + i) = temp_lst->line;
		temp_lst->line = NULL;
		temp_lst = temp_lst->next;
		i++;
	}
	*(ret + i) = NULL;
	sl_lst_clear(lst);
	return (ret);
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

int	lst_count_chars(t_sl_lst **lst_map, int c)
{
	t_sl_lst	*traverse;
	int			ctr;

	ctr = 0;
	traverse = *lst_map;
	while (traverse)
	{
		ctr += sl_count_char(traverse->line, c);
		traverse = traverse->next;
	}
	return (ctr);
}

int	sl_check_pos(t_sl_lst **lst_map)
{
	int	ctr;

	ctr = lst_count_chars(lst_map, 'P');
	ctr += lst_count_chars(lst_map, 'E');
	if (ctr != 2)
	{
		sl_lst_clear(lst_map);
		sl_map_error("Start Position or Exit ERROR\n", 6);
	}
	return (1);
}

int check_char_set_helper(char	*str)
{
	char	*char_set;
	int		i;
	int		flag;

	char_set = "01PEC\n";
	while (*str)
	{
		i = 0;
		flag = 0;
		while (*(char_set + i))
		{
			if (*str == *(char_set + i))
			{
				flag = 1;
				i = 5;
			}
			i++;
		}
		if (!flag)
			return (0);
		str++;
	}
	return (1);
}

int	check_char_set(t_sl_lst **lst_map)
{
	t_sl_lst	*traverse;

	traverse = *lst_map;
	while (traverse)
	{
		if (!check_char_set_helper(traverse->line))
		{
			sl_lst_clear(lst_map);
			sl_map_error("Unrecognized Character in Map\n", 8);
		}
		traverse = traverse->next;
	}
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
