/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:04:02 by luntiet           #+#    #+#             */
/*   Updated: 2022/12/14 10:28:21 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_pixel(t_map *map, int x, int y, uint32_t color)
{
	if (x < WIDTH && x > 0 && y < HEIGHT && y > 0)
		mlx_put_pixel(map->image, x, y, color);
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
		draw_pixel(map, pixel_x, pixel_y, get_color(p1, p2, pixel_x, pixel_y));
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}

t_point	project(t_point p, t_map *map)
{
	p.x *= map->zoom;
	p.y *= map->zoom;
	p.z *= map->zoom / map->height;
	p.y -= (map->row * map->zoom) / 2;
	p.x -= (map->col * map->zoom) / 2;
	p = rotate_x(p, map->alpha);
	p = rotate_y(p, map->beta);
	p = rotate_z(p, map->gamma);
	if (map->projection == p_iso)
		p = iso(p);
	else if (map->projection == p_sphere)
		p = sphere(p, map);
	else
		p = fisheye(p);
	p.x += WIDTH / 2 + map->x_offset;
	p.y += HEIGHT / 2 + map->y_offset;
	p.color = p.color;
	return (p);
}

void	draw(t_map *map)
{
	int	i;

	i = 0;
	ft_bzero(map->image->pixels, WIDTH * HEIGHT * 4);
	while (map->points[i])
	{
		if (map->points[i + 1] != NULL && (i + 1) % map->col != 0)
			draw_line(map, project(*map->points[i], map),
				project(*map->points[i + 1], map));
		if ((i / map->col) < (map->row - 1) && map->points[i + map->col])
			draw_line(map, project(*map->points[i], map),
				project(*map->points[i + map->col], map));
		i++;
	}
}
