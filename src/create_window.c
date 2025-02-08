/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:33:06 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/02/08 22:56:36 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	sl_crt_win()
{
	int	a;

	a = 0x11223344;
	if (((unsigned char *)&a)[0] == 0x11)
		g_local_endian = 1;
	else
		g_local_endian = 0;
	printf(" => Local Endian : %d\n",g_local_endian);
	printf(" => Connection ...");
	if (!(g_mlx = mlx_init())) // establishes connection between software and hardware
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	printf(" => Window1 %dx%d \"Background\" ...", WIN1_SX, WIN1_SY);
	if (!(g_win = mlx_new_window(g_mlx, WIN1_SX, WIN1_SY, "Background"))) // opens new window titled Title1
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	printf("OK\n");
}



