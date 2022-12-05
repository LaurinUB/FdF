/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet <luntiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:36:00 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/04 18:00:46 by luntiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_point	*ft_init_point(int x, int y, int z)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	return (point);
}

t_point	**ft_init_points(char **lines)
{
	t_point	**points;
	int		row;
	int		column;
	char	**tmp;

	row = 0;
	column = 0;
	points = NULL;
	if (!lines)
		return (NULL);
	while (lines[row] != 0)
		row++;
	tmp = ft_split(lines[0], ' ');
	if (!tmp)
		return (NULL);
	while (tmp[column] != NULL)
		column++;
	ft_printf("%i, %i\n", row, column);
	ft_splitfree(tmp);
	return (NULL);
}

t_map	*ft_init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->mlx = mlx_init(WIDTH, HEIGHT, "FdF", false);
	if (!map->mlx)
		exit(EXIT_FAILURE);
	map->image = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	if (!map->image)
		exit(EXIT_FAILURE);
	map->x_pos = 0;
	map->y_pos = 0;
	return (map);
}
