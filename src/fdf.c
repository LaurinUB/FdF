/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet <luntiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:22:38 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/06 04:14:04 by luntiet          ###   ########.fr       */
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

char	*ft_read_file(char *path)
{
	char	*line;
	int		fd;
	char	*file;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
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

void	ft_parse_points(char *file, t_map *map)
{
	int		x;
	int		y;
	int		z;
	char	**lines;
	char	**column;
	int		i;
	int		j;


	z = 0;
	j = 0;
	i = 0;
	lines = ft_split(file, '\n');
	if (!lines)
		exit(EXIT_FAILURE);
	map->points = ft_init_point_lst(lines, map);
	if (!map->points)
		exit(EXIT_FAILURE);
	x = map->x_pos;
	y = map->y_pos;
	while (lines[i])
	{
		column = ft_split(lines[i], ' ');
		while (column[j])
		{
			map->points[z] = ft_init_point(x, y, ft_atoi(column[j]));
			x += 25;
			z++;
			j++;
		}
		j = 0;
		y += 25;
		x = map->x_pos;
		ft_splitfree(column);
		i++;
	}
	map->points[z] = NULL;
	ft_splitfree(lines);
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

int	main(int argc, char **argv)
{
	t_map	*map;
	char	*file;

	if (argc != 2 || !argv || !*argv)
		return (0);
	map = ft_init_map();
	if (!map)
		return (exit(EXIT_FAILURE), 1);
	file = ft_read_file(argv[1]);
	ft_parse_points(file, map);
	ft_draw(map);
	if (mlx_image_to_window(map->mlx, map->image, 0, 0) < 0)
		return (ft_putendl_fd("Failed to draw", 2), exit(1), 0);
	mlx_loop_hook(map->mlx, &ft_quit, map);
	mlx_loop(map->mlx);
	mlx_delete_image(map->mlx, map->image);
	mlx_terminate(map->mlx);
	ft_free(map);
	free(file);
	//system("leaks fdf");
	return (EXIT_SUCCESS);
}
