/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:36:00 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/13 09:31:30 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_point	*init_point(int x, int y, int z)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	point->color = COLOR;
	return (point);
}

t_point	**init_points_lst(char **lines, t_map *map)
{
	t_point	**points;

	points = malloc((mapsize(lines, map) + 1) * sizeof(t_point *));
	if (!points)
		exit_msg("Allocation for points failed");
	return (points);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (exit(EXIT_FAILURE), NULL);
	map->mlx = mlx_init(WIDTH, HEIGHT, "FdF", false);
	if (!map->mlx)
		return (exit(EXIT_FAILURE), NULL);
	map->image = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	if (!map->image)
		return (exit(EXIT_FAILURE), NULL);
	map->x = 0;
	map->y = 0;
	map->zoom = 10;
	map->height = 3;
	map->x_offset = 0;
	map->y_offset = 0;
	map->alpha = 0;
	map->beta = 0;
	map->gamma = 0;
	map->projection = p_iso;
	return (map);
}
