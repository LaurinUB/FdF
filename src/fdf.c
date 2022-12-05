/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet <luntiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:22:38 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/04 18:02:55 by luntiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_free(t_map *map)
{
	//free(map->points);
	free(map);
}

char	*ft_read_file(char *path)
{
	char	*line;
	int		fd;
	char	*file;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_putendl_fd("Error", 2), exit(1);
	file = NULL;
	line = get_next_line(fd);
	while (line)
	{
		file = ft_strjoin_gnl(file, line);
		line = get_next_line(fd);
	}
	free (line);
	close(fd);
	return (file);
}


void	ft_parse_points(char *path, t_map *map)
{
	int		x;
	int		y;
	int		z;
	char	**lines;
	char	*file;

	x = 0;
	y = 0;
	z = 0;
	file = ft_read_file(path);
	ft_printf("%s\n", file);
	lines = ft_split(file, '\n');
	map->points = ft_init_points(lines);
	ft_splitfree(lines);
	free(file);
}

int	main(int argc, char **argv)
{
	char	*path;
	t_map	*map;

	if (argc != 2 || !argv || !*argv)
		return (0);
	path = argv[1];
	map = ft_init_map();
	ft_parse_points(path, map);
	//if (mlx_image_to_window(map->mlx, map->image, 0, 0) < 0)
	//	return (ft_putendl_fd("Failed to draw", 2), 0);
	//mlx_loop(map->mlx);
	//mlx_delete_image(map->mlx, map->image);
	//mlx_terminate(map->mlx);
	ft_free(map);
	system("leaks fdf");
	return (EXIT_SUCCESS);
}
