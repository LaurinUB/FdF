/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:21:27 by luntiet           #+#    #+#             */
/*   Updated: 2022/12/06 10:53:11 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_free(t_map *map)
{
	int	i;

	i = 0;
	while (map->points[i])
	{
		free(map->points[i]);
		i++;
	}
	free(map->points);
	free(map);
}

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

void	ft_quit(void *lol)
{
	t_map	*tab;

	tab = (t_map *)lol;
	if (mlx_is_key_down(tab->mlx, MLX_KEY_ESCAPE))
	{
		mlx_delete_image(tab->mlx, tab->image);
		mlx_terminate(tab->mlx);
		ft_free(tab);
		exit(1);
	}
}
