/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:07:35 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/14 18:22:43 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <fcntl.h>
# define WIDTH 1024
# define HEIGHT 768

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
	int			x_offset;
	int			y_offset;
	double		alpha;
	double		beta;
	double		gamma;
	int			projection;
	int			party;
}	t_map;

enum e_porjection { p_iso, p_fisheye, p_curvliniear};

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
//free_utils
void		split_free(char **str);
void		free_map(t_map *map);
//controls
void		key_bindings(void *tmp);
void		mouse_bindings(t_map *map);
void		zoom(int key, t_map *map);
void		move(int key, t_map *map);
void		mod_height(int key, t_map *map);
void		change_projection(t_map *map);
//rotation
t_point		rotate_x(t_point p, double alpha);
t_point		rotate_y(t_point p, double beta);
t_point		rotate_z(t_point p, double gamma);
//projection
t_point		iso(t_point point);
t_point		fisheye(t_point point);
t_point		curvlinear(t_point point);
//color
uint32_t	get_color(t_point start, t_point end, int current_x, int current_y);
void		set_color(t_map *map);
#endif
