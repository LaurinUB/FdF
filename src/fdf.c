/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet <luntiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:22:38 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/29 23:10:54 by luntiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char **argv)
{
	char	*path;
	t_map	*map;

	if (argc != 2 || !argv || !*argv)
		return (0);
	path = ft_strdup("./test_maps/");
	path = ft_strjoin(path, argv[1]);
	map = ft_init_map();
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
	free(path);
	return (EXIT_SUCCESS);
}
