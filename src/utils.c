/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:21:27 by luntiet           #+#    #+#             */
/*   Updated: 2022/12/08 14:59:21 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	quit(t_map *map)
{
	mlx_delete_image(map->mlx, map->image);
	mlx_terminate(map->mlx);
	free(map);
	exit(EXIT_SUCCESS);
}

void	key_bindings(void *map)
{
	t_map	*tmp;

	tmp = (t_map *)map;
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_ESCAPE))
	{
		mlx_delete_image(tmp->mlx, tmp->image);
		mlx_terminate(tmp->mlx);
		free_map(tmp);
		exit(EXIT_SUCCESS);
	}
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_UP))
		zoom(MLX_KEY_UP, map);
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_DOWN))
		zoom(MLX_KEY_DOWN, map);
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_W))
		move(MLX_KEY_W, map);
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_A))
		move(MLX_KEY_A, map);
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_S))
		move(MLX_KEY_S, map);
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_D))
		move(MLX_KEY_D, map);

}

int	mapsize(char **lines, t_map *map)
{
	int		row;
	int		column;
	char	**tmp;

	row = 0;
	column = 0;
	if (!lines)
		exit_msg("No line given to mapsize");
	while (lines[row] != 0)
		row++;
	tmp = ft_split(lines[0], ' ');
	if (!tmp)
		exit_msg("Split failed for mapsize");
	while (tmp[column] != NULL)
		column++;
	map->row = row;
	map->col = column;
	split_free(tmp);
	return (column * row);
}

void	exit_msg(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	loop_map(int x_offset, int y_offset, t_map *map)
{
	int	i;

	i = 0;
	while (map->points[i])
	{
		map->points[i]->x += x_offset;
		map->points[i]->y += y_offset;
		i++;
	}
}
