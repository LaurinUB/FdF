/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:30:24 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/09 16:17:08 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_point	rotate_x(t_point p, double alpha)
{
	int	y;
	int	z;

	y = p.y;
	z = p.z;
	p.y = y * cos(alpha) + z * sin(alpha);
	p.z = -y * sin(alpha) + z * cos(alpha);
	return (p);
}

t_point	rotate_y(t_point p, double beta)
{
	int	x;
	int	z;

	x = p.x;
	z = p.y;
	p.x = x * cos(beta) + z * sin(beta);
	p.z = -x * sin(beta) + z * cos(beta);
	return (p);
}

t_point	rotate_z(t_point p, double gamma)
{
	int	x;
	int	y;

	x = p.x;
	y = p.y;
	p.x = x * cos(gamma) - y * sin(gamma);
	p.y = x * sin(gamma) + y * cos(gamma);
	return (p);
}
