/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:04:02 by luntiet           #+#    #+#             */
/*   Updated: 2022/12/07 17:47:13 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

//(x - y) * cos(0.523599),
//(-1 * ft_atoi(column[j])) +(x + y) * sin(0.523599),
//ft_atoi(column[j])

void	draw_pixel(t_map *map, int x, int y)
{
	if (x < WIDTH && x > 0 && y < HEIGHT && y > 0)
		mlx_put_pixel(map->image, x, y, 0xFFFFFFFF);
}

void	draw_line(t_map *map, t_point *p1, t_point *p2)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;

	delta_x = p2->x - p1->x;
	delta_y = p2->y - p1->y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = p1->x;
	pixel_y = p1->y;
	while (pixels)
	{
		draw_pixel(map, pixel_x, pixel_y);
		pixel_x += delta_x;
		pixel_y += delta_y;
		pixels--;
	}
}

t_point	*iso(t_point *point)
{
	int		x;
	int		y;
	t_point	*tmp;

	tmp = point;
	x = (point->x - point->y) * cos(0.523599);
	y = (-1 * point->z) + (point->x + point->y) *sin(0.523599);
	tmp->x = x;
	tmp->y = y;
	return (tmp);
}

void	draw(t_map *map)
{
	int	i;

	i = 0;
	while (map->points[i])
	{
		draw_pixel(map, iso(map->points[i])->x, iso(map->points[i])->y);
		if (map->points[i + 1] != NULL && (i + 1) % map->col != 0)
			draw_line(map, iso(map->points[i]), iso(map->points[i + 1]));
		if (i / map->col < map->row - 1 && map->points[i + map->col])
			draw_line(map, iso(map->points[i]), iso(map->points[i + map->col]));
		i++;
	}
}
