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

int	g_local_endian;

#define	WIN1_SX		1980
#define	WIN1_SY		1080
#define	IM1_SX		32
#define	IM1_SY		32

int	color_map_1(void *win,int w,int h, void *g_mlx)
{
  int	x;
  int	y;
  int	color;

  x = w;
  while (x--)
  {
    y = h;
    while (y--)
      {
        color = (x*255)/w+((((w-x)*255)/w)<<16)+(((y*255)/h)<<8);
  mlx_pixel_put(g_mlx,win,x,y,color);
      }
  }
}

// draw map
int	draw_map(char **map, int p_row, int p_col)
{
	// draw a 
}

int	key_win1(int key, void *p)
{
	printf("Key in Win1 : %d\n",key);
	if (key == 97)
	{
	mlx_clear_window(g_mlx, g_win);
	int  i = 0;
	int  j = 0;
	while (i < WIN1_SY)
	{
		j = 0;
		while (j < WIN1_SX)
		{
			mlx_put_image_to_window(g_mlx, g_win, g_bkgd_img, j, i);
			j += xpm1_x;
		}
		i += xpm1_y;
	}
	mlx_put_image_to_window(g_mlx, g_win, g_wall_img, 32, 32);
	}
	if (key==0xFF1B) // if escape
		exit(0);
	return (1);
}

int	color_map_2(unsigned char *data,int bpp,int sl,int w,int h,int endian, int type);

int	main(int argc, char **argv)
{
	char  **map;
	int		a;

	if (argc != 2)// && !ft_strstr(argv[1], ".ber"))
	{
		ft_printf("Invalid Input\n");
		return (0);
	}
	map = is_map_valid(argv[1]);
	sl_crt_win();
	// a = 0x11223344;
	// if (((unsigned char *)&a)[0] == 0x11)
	// 	g_local_endian = 1;
	// else
	// 	g_local_endian = 0;
	// printf(" => Local Endian : %d\n",g_local_endian);
	// printf(" => Connection ...");
	// if (!(g_mlx = mlx_init())) // establishes connection between software and hardware
	// {
	// 	printf(" !! KO !!\n");
	// 	exit(1);
	// }
	// printf(" => Window1 %dx%d \"Background\" ...", WIN1_SX, WIN1_SY);
	// if (!(g_win = mlx_new_window(g_mlx, WIN1_SX, WIN1_SY, "Background"))) // opens new window titled Title1
	// {
	// 	printf(" !! KO !!\n");
	// 	exit(1);
	// }
	// printf("OK\n");


	printf(" => Xpm from file ...");
	if (!(g_bkgd_img = mlx_xpm_file_to_image(g_mlx,"./images/dark_green.xpm",&xpm1_x,&xpm1_y)))
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	data1 = mlx_get_data_addr(g_bkgd_img,&bpp1,&sl1,&endian1);
	printf("OK (xpm %dx%d)(img bpp2: %d, sizeline2: %d endian: %d type: %d)\n",
	 xpm1_x,xpm1_y,bpp1,sl1,endian1,((t_img *)g_bkgd_img)->type);
	sleep(2);

	printf(" => Put xpm ...");
	int  i = 0;
	int  j = 0;
	while (i < WIN1_SY)
	{
		j = 0;
		while (j < WIN1_SX)
		{
			mlx_put_image_to_window(g_mlx, g_win, g_bkgd_img, j, i);
			j += xpm1_x;
		}
		i += xpm1_y;
	}
	if (!(g_wall_img = mlx_xpm_file_to_image(g_mlx,"images/walk_Left_Down_2.xpm",&xpm1_x,&xpm1_y)))
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	printf("OK (xpm %dx%d)(img bpp2: %d, sizeline2: %d endian: %d type: %d)\n",
	 xpm1_x,xpm1_y,bpp1,sl1,endian1,((t_img *)g_bkgd_img)->type);
	mlx_put_image_to_window(g_mlx, g_win, g_wall_img, 0, 0);

	mlx_key_hook(g_win,key_win1,0);
	printf("OK\n");
	sleep(2);



	mlx_loop(g_mlx);
	return (0);
}










// int main(int argc, char **argv)
// {
// 	printf("errno: %d\n", errno);
// 	printf("message: %s\n", strerror(errno));
// 	int fd = open(argv[1], O_RDONLY);

// 	printf("errno: %d\n", errno);
// 	printf("message: %s\n", strerror(2));
// 	perror("Perror");
// }




int	color_map_2(unsigned char *data,int bpp,int sl,int w,int h,int endian, int type)
{
  int	x;
  int	y;
  int	opp;
  int	dec;
  int	color;
  int	color2;
  unsigned char *ptr;

  opp = bpp/8;
  printf("(opp : %d) ",opp);
  y = h;
  while (y--)
    {
      ptr = data+y*sl;
      x = w;
      while (x--)
        {
	  if (type==2)
	    color = (y*255)/w+((((w-x)*255)/w)<<16)
	      +(((y*255)/h)<<8);
	  else
	    color = (x*255)/w+((((w-x)*255)/w)<<16)+(((y*255)/h)<<8);
          color2 = mlx_get_color_value(g_mlx,color);
	  dec = opp;
	  while (dec--)
	    if (endian==g_local_endian)
	      {
		if (endian)
		  *(ptr+x*opp+dec) = ((unsigned char *)(&color2))[4-opp+dec];
		else
		  *(ptr+x*opp+dec) = ((unsigned char *)(&color2))[dec];
	      }
	    else
	      {
		if (endian)
		  *(ptr+x*opp+dec) = ((unsigned char *)(&color2))[opp-1-dec];
		else
		  *(ptr+x*opp+dec) = ((unsigned char *)(&color2))[3-dec];
	      }
        }
    }
}

