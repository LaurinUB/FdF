/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:04:02 by luntiet           #+#    #+#             */
/*   Updated: 2022/12/01 19:25:38 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_splitfree(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_draw(char *line, t_map *map)
{
	int		i;
	char	**str;

	i = 0;
	line = ft_strtrim(line, "\n");
	str = ft_split(line, ' ');
	while (str[i])
	{
		//map->points[i] = ft_init_point(map->x_pos, map->y_pos, ft_atoi(str[i]))
		mlx_put_pixel(map->image, map->x_pos, map->y_pos, 0xFFFFFFFF);
		map->x_pos += 25;
		i++;
	}
	map->y_pos += 25;
	map->x_pos = 50;
	ft_splitfree(str);
	free(line);
}
