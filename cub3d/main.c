/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:56:01 by diogosan          #+#    #+#             */
/*   Updated: 2024/11/04 16:30:02 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_cleanup_and_exit(t_mlx *mlx)
{
	if (mlx->mlx_connect != NULL)
	{
		if (mlx->mlx_win != NULL)
			mlx_destroy_window(mlx->mlx_connect, mlx->mlx_win);
		mlx_destroy_display(mlx->mlx_connect);
		free(mlx->mlx_connect);
	}
	free(mlx);
	exit(0);
}

int	ft_close(t_mlx *mlx)
{
	ft_cleanup_and_exit(mlx);
	return (0);
}

void	render(int map)
{
	char	*line;
	t_mlx	*win;

	line = get_next_line(map);
	while (line != NULL)
	{
		ft_printf(line);
		free(line);
		line = get_next_line(map);
	}
	win = malloc(sizeof(t_mlx));
	win->mlx_connect = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx_connect, WIDTH, HEIGHT, "Cub");
	mlx_hook(win->mlx_win, 17, 0, ft_close, win); // Set up a hook for closing events using ft_close function
	mlx_loop(win->mlx_connect);
}

int	main(void)
{
	int	map;

	map = open("map.txt", O_RDONLY);
	render(map);
	close(map);
	return (0);
}
