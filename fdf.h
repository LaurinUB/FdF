/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:07:35 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/08 15:42:31 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <fcntl.h>
# define WIDTH 1024
# define HEIGHT 767

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	uint32_t	color;
}	t_point;

typedef struct s_map
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_point		**points;
	int			x;
	int			y;
	int			col;
	int			row;
	int			zoom;
	int			height;
}	t_map;

//init stuff
t_point		*init_point(int x, int y, int z);
t_map		*init_map(void);
t_point		**init_points_lst(char **lines, t_map *map);
//draw
void		draw(t_map *map);
//utils
void		exit_msg(char *str);
int			mapsize(char **lines, t_map *map);
void		quit(t_map *map);
void		key_bindings(void *lol);
void		loop_map(int x_offset, int y_offset, t_map *map);
//free_utils
void		split_free(char **str);
void		free_map(t_map *map);
//controls
void		zoom(int key, t_map *map);
void		move(int key, t_map *map);
void		mod_height(int key, t_map *map);
#endif
