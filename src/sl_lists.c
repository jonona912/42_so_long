/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:23:09 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/02/04 22:15:52 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_sl_lst	*sl_new_node(char *str)
{
	t_sl_lst	*new_node;

	new_node = (t_sl_lst *)malloc(sizeof(t_sl_lst));
	if (!new_node)
		return (NULL);
	new_node->line = str;
	new_node->next = NULL;
	return (new_node);
}

t_sl_lst	*sl_lst_last(t_sl_lst *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	sl_lst_add_back(t_sl_lst **lst, t_sl_lst *node)
{
	t_sl_lst	*last;

	last = sl_lst_last(*lst);
	if (last == NULL)
		*lst = node;
	else
		last->next = node;
}

void	sl_lst_clear(t_sl_lst	**lst)
{
	t_sl_lst	*nxt;

	if (!lst)
		return ;
	while (*lst)
	{
		nxt = (*lst)->next;
		free((*lst)->line);
		free(*lst);
		*lst = nxt;
	}
}

int	sl_lst_len(t_sl_lst *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
