/* ************************************************************************** */
/*                                                         */
/*                                          :::     ::::::::   */
/*   projection.c                              :+:     :+:   :+:   */
/*                                       +:+ +:+       +:+    */
/*   By: luntiet- <luntiet-@student.42.fr>        +#+  +:+      +#+      */
/*                                    +#+#+#+#+#+   +#+         */
/*   Created: 2022/12/09 23:33:33 by luntiet-        #+#   #+#          */
/*   Updated: 2022/12/12 09:37:56 by luntiet-       ###   ########.fr      */
/*                                                         */
/* ************************************************************************** */

#include "../fdf.h"

t_point	fisheye(t_point p)
{
	int	x;
	int	y;
	int	z;
	int	d;

	x = p.x;
	y = p.y;
	z = p.z;
	d = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	if (d >= 1)
	{
		p.x = (360 * x / d);
		p.y = (360 * y / d);
	}
	return (p);
}

t_point	sphere(t_point p, t_map *map)
{
	float	radius;
	double	step_x;
	double	step_y;
	float	lng;
	float	lat;

	radius = map->col / (M_PI * 2);
	step_x = (M_PI * 2) / (map->col - 1);
	step_y = M_PI / map->row;
	lng = -p.x * step_x;
	if (p.y > 0)
		lat = (p.y + (p.y) / 2) * step_y - 0.5 * step_y;
	else
		lat = p.y + ((p.y / 2) - 1) * step_y + 0.5 * step_y;
	p.x = radius + p.z * cos(lng) * sin(lat);
	p.y = radius + p.z * sin(lng) * sin(lat);
	p.z = radius + p.z * cos(lat);
	return (p);
}

t_point	iso(t_point point)
{
	int	x;
	int	y;

	x = point.x;
	y = point.y;
	point.x = (x - y) * cos(0.523599);
	point.y = (-point.z + (x + y)) * sin(0.523599);
	return (point);
}
