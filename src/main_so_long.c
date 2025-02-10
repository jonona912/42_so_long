#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

// // cc practice.c -L../minilibx-linux -lmlx_Linux -lm -lX11 -lXext -o practice && ./practice

#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"

#include "../include/so_long.h"
#include "../libft/libft.h"


void	*g_mlx;
void	*g_win;
void    *win2;
void    *win3;
void    *g_wall_img;
void	*g_bkgd_img;
void	*im3;
void	*im4;
int	bpp1;
int	bpp2;
int	bpp3;
int	bpp4;
int	sl1;
int	sl2;
int	sl3;
int	sl4;
int	endian1;
int	endian2;
int	endian3;
int	endian4;
char	*data1;
char	*data2;
char	*data3;
char	*data4;
int	xpm1_x;
int	xpm1_y;

int		g_local_endian;
int		g_win_x;
int		g_win_y;
char	**g_map;

#define	WIN1_SX		1980
#define	WIN1_SY		1080
#define	IM1_SX		32
#define	IM1_SY		32

// is move valid
void	find_pos(int *x_pos, int *y_pos)
{
	int	x;
	int	y;

	y = 0;
	while (*(g_map + y))
	{
		x = 0;
		while (*(*(g_map + y) + x))
		{
			if (*(*(g_map + y) + x) == 'P')
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

int	is_mv_valid(int x_pos, int y_pos)
{
	return (*(*(g_map + y_pos) + x_pos) == '0' || *(*(g_map + y_pos) + x_pos) == 'C');
}

int	make_move(move_dir dir)
{
	int	x_pos;
	int	y_pos;

	find_pos(&x_pos, &y_pos);
	if (dir == RIGHT && *(*(g_map + y_pos) + x_pos + 1) == 'E')
		exit(1);
	else if (dir == LEFT && *(*(g_map + y_pos) + x_pos - 1) == 'E')
		exit(1);
	else if (dir == TOP && *(*(g_map + y_pos - 1) + x_pos) == 'E')
		exit(1);
	else if (dir == DOWN && *(*(g_map + y_pos + 1) + x_pos) == 'E')
		exit(1);
	if (dir == RIGHT && is_mv_valid(x_pos + 1, y_pos))
	{
		*(*(g_map + y_pos) + x_pos) = '0';
		*(*(g_map + y_pos) + x_pos + 1) = 'P';
		return (1);
	}
	else if (dir == LEFT && is_mv_valid(x_pos - 1, y_pos))
	{
		*(*(g_map + y_pos) + x_pos) = '0';
		*(*(g_map + y_pos) + x_pos - 1) = 'P';
		return (1);
	}
	else if (dir == TOP && is_mv_valid(x_pos, y_pos - 1))
	{
		*(*(g_map + y_pos) + x_pos) = '0';
		*(*(g_map + y_pos - 1) + x_pos) = 'P';
		return (1);
	}
	else if (dir == DOWN && is_mv_valid(x_pos, y_pos + 1))
	{
		*(*(g_map + y_pos) + x_pos) = '0';
		*(*(g_map + y_pos + 1) + x_pos) = 'P';
		return (1);
	}
	return (0);
}

int	key_win1(int key, void *p)
{
	t_game_lst	*g_lst;

	g_lst = (t_game_lst *) p;
	printf("Key in Win1 : %d\n",key);
	if (key == 97 && make_move(LEFT))
	{
		mlx_clear_window(g_mlx, g_win);
		draw_map(g_map, g_lst->imgs, 0, 0);
	}
	else if(key == 100 && make_move(RIGHT))
	{
		mlx_clear_window(g_mlx, g_win);
		draw_map(g_map, g_lst->imgs, 0, 0);
	}
	else if(key == 119 && make_move(TOP))
	{
		mlx_clear_window(g_mlx, g_win);
		draw_map(g_map, g_lst->imgs, 0, 0);
	}
	else if(key == 115 && make_move(DOWN))
	{
		mlx_clear_window(g_mlx, g_win);
		draw_map(g_map, g_lst->imgs, 0, 0);
	}
	if (key==0xFF1B) // if escape
		exit(0);
	return (1);
}

int	main(int argc, char **argv)
{
	char  **map;
	int		a;
	t_game_lst	game_lst;

	if (argc != 2)// && !ft_strstr(argv[1], ".ber"))
	{
		ft_printf("Invalid Input\n");
		return (0);
	}
	map = is_map_valid(argv[1]);
	g_map = map;
	game_lst.map = map;
	sl_crt_win(map); // create window, duh

	game_lst.imgs = connect_xpm_files(&game_lst.imgs);

	printf(" => Put xpm ...");
	draw_map(map, game_lst.imgs, 0, 0);
	mlx_key_hook(g_win,key_win1,&game_lst);
	printf("OK\n");



	mlx_loop(g_mlx);
	return (0);
}
