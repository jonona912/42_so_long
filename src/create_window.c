/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:33:06 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/02/09 20:15:07 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	sl_map_dimensions(char **map, int *height, int *width)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	while (*((*map) + w))
		w++;
	while (*(map + h))
		h++;
	*height = h;
	*width = w - 1;
}

void	sl_crt_win(char **map)
{
	int	height;
	int	width;

	sl_map_dimensions(map, &height, &width);
	height *= 128;
	width *= 128;
	if (!(g_mlx = mlx_init())) // establishes connection between software and hardware
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	printf(" => Window1 %dx%d \"Background\" ...", width, height);
	if (!(g_win = mlx_new_window(g_mlx, width, height, "Background"))) // opens new window titled Title1
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	printf("OK\n");
}

void	connect_xpm_files_helper(t_img_sl *imgs)
{
	(*imgs).img = NULL;
	if (!((*imgs).img = mlx_xpm_file_to_image(g_mlx,(*imgs).img_path,&(*imgs).width,&(*imgs).height)))
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	(*imgs).data = mlx_get_data_addr((*imgs).img,&(*imgs).bpp, &(*imgs).sl,&(*imgs).endian);
	// sleep(2);
}

t_img_lst	connect_xpm_files()
{
	t_img_lst	imgs;

	imgs.player.img_path = "./images/character.xpm";
	imgs.clc.img_path = "./images/tree_128.xpm";
	imgs.exit.img_path = "./images/home.xpm";
	imgs.space.img_path = "./images/dark_green.xpm";
	imgs.wall.img_path = "./images/rocks_128.xpm";

	connect_xpm_files_helper(&(imgs.player));
	connect_xpm_files_helper(&(imgs.clc));
	connect_xpm_files_helper(&(imgs.exit));
	connect_xpm_files_helper(&(imgs.space));
	connect_xpm_files_helper(&(imgs.wall));
	return (imgs);
}


// void connect_xpm_files_helper(t_img_sl *imgs)
// {
//     imgs->img = NULL;
//     if (!(imgs->img = mlx_xpm_file_to_image(g_mlx, imgs->img_path, &imgs->width, &imgs->height)))
//     {
//         printf("Error: Failed to load image: %s\n", imgs->img_path);
//         exit(1);
//     }
//     imgs->data = mlx_get_data_addr(imgs->img, &imgs->bpp, &imgs->sl, &imgs->endian);
// }

// t_img_lst connect_xpm_files()
// {
// 	t_img_lst	imgs;

// 	imgs.player.img_path = "images/character.xpm";
// 	imgs.clc.img_path = "images/tree_128.xpm";

// 	connect_xpm_files_helper(&imgs.player);
// 	connect_xpm_files_helper(&imgs.clc);

// 	return imgs;
// }


// draw map
int	draw_map(char **map, t_img_lst imgs, int p_row, int p_col)
{
	int	i;
	int	j;
	int	x_pos;
	int	y_pos;

	x_pos = 0;
	y_pos = 0;
	i = 0;
	j = 0;
	while (*(map + i))
	{
		j = 0;
		x_pos = 0;
		while (*(*(map + i) + j) && *(*(map + i) + j) != '\n')
		{
			if (*(*(map + i) + j) == 'P')
				mlx_put_image_to_window(g_mlx, g_win, imgs.player.img, x_pos, y_pos);
			else if (*(*(map + i) + j) == 'E')
				mlx_put_image_to_window(g_mlx, g_win, imgs.exit.img, x_pos, y_pos);
			else if (*(*(map + i) + j) == 'C')
				mlx_put_image_to_window(g_mlx,g_win, imgs.clc.img, x_pos, y_pos);
			else if(*(*(map + i) + j) == '0')
				mlx_put_image_to_window(g_mlx,g_win, imgs.space.img, x_pos, y_pos);
			else if(*(*(map + i) + j) == '1')
				mlx_put_image_to_window(g_mlx,g_win, imgs.wall.img, x_pos, y_pos);
			x_pos += imgs.player.width;
			j++;
		}
		y_pos += imgs.player.height;
		i++;
	}
	return (1);
}



