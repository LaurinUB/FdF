/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:22:38 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/01 19:26:29 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_free(t_map *map)
{
	free(map->points);
	free(map);
}
void	ft_read_file(char *path, t_map *map)
{
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		ft_draw(line, map);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	char	*path;
	t_map	*map;

	if (argc != 2 || !argv || !*argv)
		return (0);
	path = argv[1];
	map = ft_init_map();
	ft_read_file(path, map);
	if (mlx_image_to_window(map->mlx, map->image, 0, 0) < 0)
		return (ft_putendl_fd("Failed to draw", 2), 0);
	mlx_loop(map->mlx);
	mlx_delete_image(map->mlx, map->image);
	mlx_terminate(map->mlx);
	ft_free(map);
	system("leaks fdf");
	return (EXIT_SUCCESS);
}
