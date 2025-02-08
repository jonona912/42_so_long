/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:24:05 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/02/08 22:47:09 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>

# include "../gnl/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"


// from test file ========
extern void	*g_mlx;
extern void	*g_win;
extern int	g_local_endian;
#define	WIN1_SX		1980
#define	WIN1_SY		1080
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

typedef struct s_img_lst
{
	void	*player;
	void	*wall;
	void	*space;
	void	*exit;
	void	*clc;
}	t_img_lst;




// check_map_path.c
int	check_map_path(char ***map, int collectible);



// check_map_wall.c
void	sl_map_error(char *str, int n);
int	check_wall(char	*str);
int	check_top_bottom_wall(t_sl_lst	*map_lst);
int	check_str_sides(char *str);
int	check_for_wall(t_sl_lst	**map_lst);

// sl_lists.c
t_sl_lst	*sl_new_node(char *str);
t_sl_lst	*sl_lst_last(t_sl_lst *lst);
void		sl_lst_add_back(t_sl_lst **lst, t_sl_lst *node);
void		sl_lst_clear(t_sl_lst **lst);
int	sl_lst_len(t_sl_lst *lst);

// map_validity.c
char		**is_map_valid(char *map);
int			sl_strlen(char *str);


void	sl_crt_win();


#endif
