/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:25:13 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/14 10:12:10 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	safe_exit(t_map *map)
{
	mlx_delete_image(map->mlx, map->image);
	mlx_terminate(map->mlx);
	free_map(map);
	exit(EXIT_SUCCESS);
}

void	key_bindings(void *tmp)
{
	t_map	*map;

	map = (t_map *)tmp;
	mouse_bindings(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		safe_exit(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_UP))
		zoom(MLX_KEY_UP, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
		zoom(MLX_KEY_DOWN, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_W))
		move(MLX_KEY_W, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_A))
		move(MLX_KEY_A, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_S))
		move(MLX_KEY_S, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_D))
		move(MLX_KEY_D, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
		mod_height(MLX_KEY_RIGHT, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
		mod_height(MLX_KEY_LEFT, map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_P))
		change_projection(map);
}
