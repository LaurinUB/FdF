/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:22:38 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/28 18:25:35 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char **argv)
{
	int	fd;
	char	*str;

	str = ft_strdup("./test_maps/");
	if (argc != 2 || !argv || !*argv)
		return (0);
	str = ft_strjoin(str, argv[1]);
	ft_printf("%s\n", str);
	fd = open(str, O_RDONLY);
	ft_printf("%s\n", get_next_line(fd));
	free(str);
	return (0);
}
