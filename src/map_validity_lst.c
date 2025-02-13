/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:21:39 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/02/13 19:23:41 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**sl_convert_lst_str(t_sl_lst **lst)
{
	int			lst_len;
	char		**ret;
	int			i;
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
	int	exit_num;
	int	pos_num;

	exit_num = lst_count_chars(lst_map, 'P');
	pos_num += lst_count_chars(lst_map, 'E');
	if (exit_num != 1 || pos_num != 1)
	{
		sl_lst_clear(lst_map);
		sl_map_error("Start Position or Exit ERROR\n", 6);
	}
	return (1);
}

int	check_char_set_helper(char *str)
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
