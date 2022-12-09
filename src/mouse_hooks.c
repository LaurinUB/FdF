/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:33:18 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/09 16:14:23 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	mouse_bindings(t_map *map)
{
	int		x;
	int		y;

	x = map->x;
	y = map->y;
	mlx_get_mouse_pos(map->mlx, &map->x, &map->y);
	if (mlx_is_mouse_down(map->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		map->gamma += (map->x - x) * 0.002;
		map->alpha += (map->y - y) * 0.002;
		map->beta += (map->x - x) * 0.002;
	}
	draw(map);
}
