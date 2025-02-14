/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:37:55 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/02/14 18:10:35 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_window(t_game_lst *g_lst)
{
	sl_free_game_mem(g_lst, IS_IMAGE);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game_lst	game_lst;

	if (argc != 2 || !ft_strstr_last(argv[1], ".ber"))
	{
		ft_printf("Invalid Input/map\n");
		return (0);
	}
	game_lst.map = is_map_valid(argv[1]);
	game_lst = sl_crt_win(&game_lst);
	game_lst.mv_ctr = 0;
	connect_xpm_files(&game_lst);
	draw_map(&game_lst);
	mlx_key_hook(game_lst.win, key_response, &game_lst);
	mlx_hook(game_lst.win, 17, 0, close_window, &game_lst);
	mlx_loop(game_lst.mlx);
	return (0);
}
