/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet <luntiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:36:00 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/29 23:08:38 by luntiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_map	*ft_init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->mlx = mlx_init(WIDTH, HEIGHT, "FdF", false);
	if (!map->mlx)
		exit(EXIT_FAILURE);
	map->image = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	if (!map->image)
		exit(EXIT_FAILURE);
	return (map);
}
