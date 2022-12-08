/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:46:14 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/08 14:58:19 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	zoom(int key, t_map *map)
{
	if (key == MLX_KEY_UP)
	{
		map->zoom += 1;
	;
	}
	else if (key == MLX_KEY_DOWN)
	{
		map->zoom -= 1;
		if (map->zoom < 1)
			map->zoom = 1;
	}
	draw(map);
}

void	move(int key, t_map *map)
{
	if (key == MLX_KEY_A)
		loop_map(-1, 0, map);
	if (key == MLX_KEY_D)
		loop_map(1, 0, map);
	if (key == MLX_KEY_W)
		loop_map(0, -1, map);
	if (key == MLX_KEY_S)
		loop_map(0, 1, map);
	draw(map);
}
