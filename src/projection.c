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
	float	d;

	d = sqrt(pow(p.x, 2) + pow(p.y, 2) + pow(p.z, 2));
	if (d != 0)
	{
		p.x = (180 * p.x) / d;
		p.y = (180 * p.y) / d;
	}
	return (p);
}

t_point	curvlinear(t_point p)
{
	float	d;

	d = sqrt(pow(p.x, 2) + pow(p.y, 2) + pow(p.z, 2));
	if (d != 0)
		p.x = (180 * p.x) / d;
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
