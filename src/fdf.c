/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:22:38 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/13 10:17:23 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	*read_file(char *path)
{
	char	*line;
	int		fd;
	char	*file;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	file = NULL;
	line = get_next_line(fd);
	while (line)
	{
		file = ft_strjoin_gnl(file, line);
		free(line);
		line = get_next_line(fd);
	}
	free (line);
	close(fd);
	return (file);
}

void	fill_points(char **lines, t_map *map)
{
	char	**column;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (lines[i])
	{
		column = ft_split(lines[i], ' ');
		while (column[j])
		{
			map->points[k] = init_point(j, i, ft_atoi(column[j]));
			k++;
			j++;
		}
		j = 0;
		i++;
		split_free(column);
	}
	map->points[k] = NULL;
}

void	parse_points(char *path, t_map *map)
{
	char	**lines;
	char	*file;

	file = read_file(path);
	if (!file)
		quit(map);
	lines = ft_split(file, '\n');
	if (!lines)
		quit(map);
	map->points = init_points_lst(lines, map);
	if (!map->points)
	{
		split_free(lines);
		free_map(map);
		exit_msg("Failed to init list of points");
	}
	fill_points(lines, map);
	free(file);
	split_free(lines);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2 || !argv || !*argv)
		exit_msg("Function should be called by ./fdf ./path/to/file");
	map = init_map();
	if (!map)
		exit_msg("Failed to init map struct");
	parse_points(argv[1], map);
	set_color(map->points);
	draw(map);
	if (mlx_image_to_window(map->mlx, map->image, 0, 0) < 0)
		exit_msg("Failed to draw");
	mlx_loop_hook(map->mlx, &key_bindings, map);
	mlx_loop(map->mlx);
	mlx_delete_image(map->mlx, map->image);
	mlx_terminate(map->mlx);
	free_map(map);
	return (EXIT_SUCCESS);
}
