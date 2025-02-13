/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:24:05 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/02/13 19:32:58 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>

# include "../gnl/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

#define WIDTH 128
#define HEIGHT 128
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
	char	*path;
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
	int			mv_ctr;
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


typedef enum
{
	NO_IMAGE,
	IS_IMAGE
} is_image;


// check_map_path.c
int	check_map_path(char ***map, int collectible);


// check_map_wall.c
void	sl_map_error(char *str, int n);
int	check_wall(char	*str);
int	check_top_bottom_wall(t_sl_lst	*map_lst);
int	check_str_sides(char *str);
int	check_for_wall(t_sl_lst	**map_lst);

//  create_window.c
void	sl_map_dimensions(char **map, int *height, int *width);
t_game_lst	sl_crt_win(t_game_lst *g_lst);
void	connect_xpm_files_helper(t_img_sl *imgs, t_game_lst *g_lst);
void	connect_xpm_files(t_game_lst *g_lst);

// making_movements.c
void	find_pos(t_game_lst *g_lst, int *x_pos, int *y_pos);
void	set_positions(move_dir dir, int *x_pos, int *y_pos);
int	make_move(t_game_lst *g_lst, move_dir dir);
int	sl_is_move(int key, t_game_lst *g_lst);
int	key_response(int key, void *p);

// sl_draw_map.c
void	connect_xpm_files(t_game_lst *g_lst);
int	draw_map_helper(t_game_lst *g_lst, int i, int y);
int	draw_map(t_game_lst *g_lst);

// sl_free_mem.c
int	sl_free_game_mem(t_game_lst *g_lst, is_image status);
void sl_free_double_str(char ***str);

// sl_lists.c
t_sl_lst	*sl_new_node(char *str);
t_sl_lst	*sl_lst_last(t_sl_lst *lst);
void		sl_lst_add_back(t_sl_lst **lst, t_sl_lst *node);
void		sl_lst_clear(t_sl_lst **lst);
int	sl_lst_len(t_sl_lst *lst);

// map_validity_lst.c
char	**sl_convert_lst_str(t_sl_lst **lst);
int	lst_count_chars(t_sl_lst **lst_map, int c);
int	sl_check_pos(t_sl_lst **lst_map);
int	check_char_set_helper(char *str);
int	check_char_set(t_sl_lst **lst_map);

// map_validity.c
int			sl_strlen(char *str);
void	sl_free_str_lst(t_sl_lst **lst_map, char *line);
void	create_map_list(t_sl_lst **lst_map, int fd);
int	sl_count_char(char	*str, int c);
char		**is_map_valid(char *map);





#endif
