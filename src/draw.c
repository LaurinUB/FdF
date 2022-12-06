/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet <luntiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:04:02 by luntiet           #+#    #+#             */
/*   Updated: 2022/12/06 04:03:42 by luntiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_draw_line(t_map *map, t_point p1, t_point p2)
{
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;
	int		pixels;

	delta_x = p2.x - p1.x;
	delta_y = p2.y - p1.y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = p1.x;
	pixel_y = p1.y;
	while (pixels)
	{
		mlx_put_pixel(map->image, pixel_x, pixel_y, 0xFFFFFFFF);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}
//(x - y) * cos(0.523599), (-1 * ft_atoi(column[j])) +(x + y) * sin(0.523599), ft_atoi(column[j])
void	ft_draw(t_map *map)
{
	int	i;

	i = 0;
	while (map->points[i])
	{
		if (map->points[i]->x < WIDTH && map->points[i]->x > 0)
			if (map->points[i]->y < HEIGHT && map->points[i]->y > 0)
				mlx_put_pixel(map->image, map->points[i]->x, map->points[i]->y, 0xFFFFFFFF);
		//if (map->points[i + 1] != NULL && (i + 1) % map->col != 0)
		//	ft_draw_line(map, *map->points[i], *map->points[i + 1]);
		//if (i / map->col < map->row - 1 && map->points[i + map->row])
		//	ft_draw_line(map, *map->points[i], *map->points[i + map->row]);
		i++;
	}
}
