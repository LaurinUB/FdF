/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:36:00 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/29 11:03:25 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_init_map(char *path)
{
	int		fd;
	mlx_t	*mlx;

	path = NULL;
	fd = 0;
	mlx = mlx_init(200, 200, "FdF", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
