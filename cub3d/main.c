/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:56:01 by diogosan          #+#    #+#             */
/*   Updated: 2024/11/29 13:55:32 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_vision_angle(t_mlx *win, float px, float py)
{
	float	x_step;
	float	y_step;
	int		max;
	int		end_x;
	int		end_y;

	end_x = px + 5 * win->player->player_delta_x;
	end_y = py + 5 * win->player->player_delta_y;
	x_step = end_x - px;
	y_step = end_y - py;


	max = fmax(ft_mod(x_step), ft_mod(y_step));
	x_step /= max;
	y_step /= max;

	while ((int)(px - end_x) || (int)(py - end_y))
	{
		my_pixel_put(&win->img, px, py, 0xff00ff);
		px += x_step;
		py += y_step;
	}
}


void	ft_bresenhams_alg(t_mlx *win, float end_x, float end_y, int color)
{
	float	x_step;
	float	y_step;
	float	px;
	float	py;
	int		max;

	px = win->player->player_x;
	py = win->player->player_y;
	x_step = end_x - px;
	y_step = end_y - py;


	max = fmax(ft_mod(x_step), ft_mod(y_step));
	x_step /= max;
	y_step /= max;

	while ((int)(px - end_x) || (int)(py - end_y))
	{
		my_pixel_put(&win->img, px, py, color);
		px += x_step;
		py += y_step;
	}
}

int	draw(t_mlx *win)
{
	render_background(&win->img, 0xD3D3D3);
	ft_draw_map(win->map, &win->img, win);
	ft_update_player(win->player->player_x, win->player->player_y, &win->img, win);
	ft_vision_angle(win, win->player->player_x, win->player->player_y);
	render_background_top_bot(&win->img);
	raycaster(win);
	mlx_put_image_to_window(win->mlx_connect, win->mlx_win,
		win->img.mlx_img, 0, 0);
	return (0);
}

void	render(t_mlx *win) //render(char **map)
{
	win->mlx_connect = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx_connect, WIDTH, HEIGHT, "Cub3D");
	win->img.mlx_img = mlx_new_image(win->mlx_connect, WIDTH, HEIGHT);
	win->img.addr = mlx_get_data_addr(win->img.mlx_img, &win->img.bpp,
			&win->img.line_len, &win->img.endian);
	// North texture
	win->north_texture.mlx_img = mlx_xpm_file_to_image(win->mlx_connect,
			"./assets/north_texture.xpm", &win->north_texture.width,
			&win->north_texture.height);
	win->north_texture.addr = mlx_get_data_addr(win->north_texture.mlx_img,
			&win->north_texture.bpp, &win->north_texture.line_len,
			&win->north_texture.endian);

	// South texture
	win->south_texture.mlx_img = mlx_xpm_file_to_image(win->mlx_connect,
			"./assets/south_texture.xpm", &win->south_texture.width,
			&win->south_texture.height);
	win->south_texture.addr = mlx_get_data_addr(win->south_texture.mlx_img,
			&win->south_texture.bpp, &win->south_texture.line_len,
			&win->south_texture.endian);

	// East texture
	win->east_texture.mlx_img = mlx_xpm_file_to_image(win->mlx_connect,
			"./assets/east_texture.xpm", &win->east_texture.width,
			&win->east_texture.height);
	win->east_texture.addr = mlx_get_data_addr(win->east_texture.mlx_img,
			&win->east_texture.bpp, &win->east_texture.line_len,
			&win->east_texture.endian);

	// West texture
	win->west_texture.mlx_img = mlx_xpm_file_to_image(win->mlx_connect,
			"./assets/west_texture.xpm", &win->west_texture.width,
			&win->west_texture.height);
	win->west_texture.addr = mlx_get_data_addr(win->west_texture.mlx_img,
			&win->west_texture.bpp, &win->west_texture.line_len,
			&win->west_texture.endian);

	mlx_loop_hook(win->mlx_connect, &draw, win);
	mlx_key_hook(win->mlx_win, arrow_keys, win);
	mlx_hook(win->mlx_win, KeyPress, KeyPressMask, ft_event_checker, win);
	mlx_hook(win->mlx_win, 17, 0, ft_close, win);
	mlx_loop(win->mlx_connect);
}

int	main(void)
{
	char	*data[] =
	{
	"111111111111111111",
	"100000N00011000001",
	"111100111111110111",
	"111100011111110111",
	"110000001101010111",
	"100000000000000011",
	"100000000000000011",
	"110000011101010111",
	"111101111111010111",
	"111111111111111111"};

	t_mlx	*win;

	win = malloc(sizeof(t_mlx));
	set_up_win(win, data);
	render(win);
	return (0);
}
