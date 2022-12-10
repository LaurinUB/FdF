/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 23:33:33 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/09 23:34:45 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_point sphere(t_point point, t_map *map)
{
    int z;
    double radius;
    float   x_steps;
    float   y_steps;
    float   LONG;
    float   LAT;

    z = point.z;
    x_steps = (M_PI * 2) / (map->col - 1);
    y_steps = M_PI / map->row;
    LAT = point.y + (point.y / 2) * y_steps - 0.5 * y_steps;
    LONG = (-1 * point.x) * x_steps;
    radius = map->col / (M_PI * 2);
    point.x = (radius + z) * cos(LONG) * sin(LAT);
    point.y = (radius + z) * sin(LONG) * sin(LAT);
    point.z = (radius + z) * cos(LAT);
    return (point);
}

t_point fisheye(t_point point)
{
    float   r;
    float   phi;
    float   theta;
    
    r = sqrt((point.z * point.z) + (point.x * point.x));
    phi = 0.5 * r * M_PI;
    theta = atan2(point.z, point.x);
    point.x = sin(phi) * cos(theta);
    point.y = cos(phi);
    return (point);
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
