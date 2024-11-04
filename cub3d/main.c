/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:56:01 by diogosan          #+#    #+#             */
/*   Updated: 2024/11/04 16:11:30 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <time.h>

void	render(int map)
{
	char	*line;

	line = get_next_line(map);
	while (line != NULL)
	{
		ft_printf(line);
		free(line);
		line = get_next_line(map);
	}
}

int	main(void)
{
	int	map;

	map = open("map.txt", O_RDONLY);
	render(map);
	close(map);
	return (0);
}
