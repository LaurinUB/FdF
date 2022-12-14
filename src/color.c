/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:18:04 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/14 10:22:32 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (placement / distance);
}

uint32_t	get_light(int start, int end, double percentage)
{
	return ((int)(1 - percentage) *start + percentage * end);
}

uint32_t	get_color(t_point start, t_point end, int current_x, int current_y)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (start.color == end.color)
		return (start.color);
	if (current_x > current_y)
		percentage = percent(start.x, end.x, current_x);
	else
		percentage = percent(start.y, end.y, current_y);
	red = get_light(((start.color >> 24) & 0xFF),
			((end.color >> 24) & 0xFF), percentage);
	green = get_light(((start.color >> 16) & 0xFF),
			((end.color >> 16) & 0xFF), percentage);
	blue = get_light(((start.color >> 8) & 0xFF),
			((end.color >> 8) & 0xFF), percentage);
	return ((red << 24) + (green << 16) + (blue << 8) + 0xFF);
}

uint32_t	base_color(t_point *p)
{
	int	red;
	int	green;
	int	blue;
	int	z;

	z = p->z;
	if (p->z < 0)
		z *= -1;
	red = ((p->color >> 24) & 0xFF) + (z * 8);
	green = ((p->color >> 16) & 0xFF) + (z * 4);
	blue = ((p->color >> 8) & 0xFF) + (z);
	return ((red << 24) + (green << 16) + (blue << 8) + 0xFF);
}

void	set_color(t_point **p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		p[i]->color = base_color(p[i]);
		i++;
	}
}
