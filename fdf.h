/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet <luntiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:07:35 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/29 23:11:34 by luntiet          ###   ########.fr       */
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
}	t_map;

//init stuff
t_map		*ft_init_map(void);
#endif
