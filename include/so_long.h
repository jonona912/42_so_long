/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:24:05 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/02/10 10:14:37 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>

# include "../gnl/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"


// from test file ========
extern void	*g_mlx;
extern void	*g_win;
extern int	g_local_endian;
extern int	g_win_x;
extern int	g_win_y;
extern char	**g_map;
// extern t_img_lst	g_imgs;

#define	WIN1_SX		1980
#define	WIN1_SY		1080

#define WIDTH 64
#define HEIGHT 64
// ==================

typedef struct	s_sl_lst
{
	char			*line;
	struct s_sl_lst	*next;
}	t_sl_lst;

typedef struct map_c
{
	int	pos;
	int	ext;
	int	clc;
}	map_c_count;

typedef struct s_map_char
{
	char clc;
	char exit;
	char position;
	char wall;
	char space;
}	t_map_chars;

typedef struct s_img_sl
{
	void	*img;
	char	*img_path;
	int		width;
	int		height;
	char	*data;
	int		bpp;
	int		sl;
	int		endian;
}	t_img_sl;

typedef struct s_img_lst
{
	t_img_sl	player;
	t_img_sl	wall;
	t_img_sl	space;
	t_img_sl	exit;
	t_img_sl	clc;
}	t_img_lst;

typedef struct s_game_lst
{
	t_img_lst	imgs;
	char		**map;
	int			x;
	int			y;
	void		*win;
	void		*mlx;
} t_game_lst;


typedef enum {
	LEFT,
	RIGHT,
	TOP,
	DOWN
} move_dir;


// check_map_path.c
int	check_map_path(char ***map, int collectible);



// check_map_wall.c
void	sl_map_error(char *str, int n);
int	check_wall(char	*str);
int	check_top_bottom_wall(t_sl_lst	*map_lst);
int	check_str_sides(char *str);
int	check_for_wall(t_sl_lst	**map_lst);

//  create_window.c
void	sl_crt_win();
t_img_lst	connect_xpm_files();

// sl_lists.c
t_sl_lst	*sl_new_node(char *str);
t_sl_lst	*sl_lst_last(t_sl_lst *lst);
void		sl_lst_add_back(t_sl_lst **lst, t_sl_lst *node);
void		sl_lst_clear(t_sl_lst **lst);
int	sl_lst_len(t_sl_lst *lst);

// map_validity.c
char		**is_map_valid(char *map);
int			sl_strlen(char *str);
int	draw_map(char **map, t_img_lst imgs, int p_row, int p_col);

void	sl_crt_win(char **map);






#endif
