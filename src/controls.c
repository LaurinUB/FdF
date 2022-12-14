/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:46:14 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/14 18:18:50 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	zoom(int key, t_map *map)
{
	if (key == MLX_KEY_UP)
		map->zoom += 1;
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
		map->x_offset -= 10;
	if (key == MLX_KEY_D)
		map->x_offset += 10;
	if (key == MLX_KEY_W)
		map->y_offset -= 10;
	if (key == MLX_KEY_S)
		map->y_offset += 10;
	draw(map);
}

void	mod_height(int key, t_map *map)
{
	if (key == MLX_KEY_RIGHT)
		map->height += 1;
	if (key == MLX_KEY_LEFT)
	{
		map->height -= 1;
		if (map->height < 1)
			map->height = 1;
	}
	draw(map);
}

void	change_projection(t_map *map)
{
	if (mlx_is_key_down(map->mlx, MLX_KEY_1))
		map->projection = p_iso;
	else if (mlx_is_key_down(map->mlx, MLX_KEY_2))
		map->projection = p_fisheye;
	else if (mlx_is_key_down(map->mlx, MLX_KEY_3))
		map->projection = p_curvliniear;
	else if (mlx_is_key_down(map->mlx, MLX_KEY_I))
		map->party = 1;
	else if (mlx_is_key_down(map->mlx, MLX_KEY_O))
		map->party = 0;
	draw(map);
}
