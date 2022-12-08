/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet <luntiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:04:02 by luntiet           #+#    #+#             */
/*   Updated: 2022/12/08 09:21:13 by luntiet          ###   ########.fr       */
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

void	draw_line(t_map *map, t_point p1, t_point p2)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;

	delta_x = p2.x - p1.x;
	delta_y = p2.y - p1.y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = p1.x;
	pixel_y = p1.y;
	while (pixels)
	{
		draw_pixel(map, pixel_x, pixel_y);
		pixel_x += delta_x;
		pixel_y += delta_y;
		pixels--;
	}
}

t_point	iso(t_point point)
{
	int		x;
	int		y;

	x = point.x;
	y = point.y;
	point.x = (x - y) * cos(0.523599);
	point.y = (-1 * point.z) + (x + y) *sin(0.523599);
	return (point);
}

t_point project(t_point p, t_map *map)
{
	//ft_printf("after projection %i\n", p->x);
	p.x *= map->zoom;
	//ft_printf("before projection %i\n", p->x);
	p.y *= map->zoom;
	p.z *= map->zoom / map->z_height;
	p = iso(p);
	p.x += WIDTH / 2;
	p.y += HEIGHT / 2;
	return (p);
}

void	draw(t_map *map)
{
	int	i;

	i = 0;
	while (map->points[i])
	{
		draw_pixel(map, project(*map->points[i], map).x, project(*map->points[i], map).y);
		if (map->points[i + 1] != NULL && (i + 1) % map->col != 0)
			draw_line(map, project(*map->points[i], map),
				project(*map->points[i + 1], map));
		if (i / map->col < map->row - 1 && map->points[i + map->col])
			draw_line(map, project(*map->points[i], map),
				project(*map->points[i + map->col], map));
		i++;
	}
}
