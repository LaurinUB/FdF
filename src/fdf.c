/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet <luntiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:22:38 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/30 00:39:26 by luntiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	*ft_read_file(char *path)
{
	char	*line;
	char	*file;
	int		fd;

	file = ft_strdup("");
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		file = ft_strjoin(file, line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (file);
}

int	main(int argc, char **argv)
{
	char	*path;
	t_map	*map;
	char	*file;

	if (argc != 2 || !argv || !*argv)
		return (0);
	path = ft_strdup("./test_maps/");
	path = ft_strjoin(path, argv[1]);
	map = ft_init_map();
	file = ft_read_file(path);
	ft_printf("%s", file);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
	free(path);
	return (EXIT_SUCCESS);
}
