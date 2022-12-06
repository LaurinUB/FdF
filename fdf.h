/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:07:35 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/06 10:53:41 by luntiet-         ###   ########.fr       */
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
	int	x;
	int	y;
	int	z;
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
}	t_map;

//init stuff
t_point		*ft_init_point(int x, int y, int z);
t_map		*ft_init_map(void);
t_point		**ft_init_point_lst(char **lines, t_map *map);
//draw
void		ft_draw(t_map *map);
//utils
void		ft_splitfree(char **str);
void		ft_quit(void *lol);
void		ft_free(t_map *map);
#endif
