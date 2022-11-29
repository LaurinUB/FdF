/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:07:35 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/29 11:32:18 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <fcntl.h>

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_stuff
{
	struct t_point	*point;

}	t_stuff;

//init stuff
void		ft_init_map(char *path);
#endif
