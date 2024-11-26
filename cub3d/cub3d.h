/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:56:41 by diogosan          #+#    #+#             */
/*   Updated: 2024/11/26 15:25:13 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libraries/libft/libft.h"
# include "libraries/printf/ft_printf.h"
# include <stdio.h>
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define PI 3.14159265359
# define P2 1.57079632679 // PI/2
# define P3 4.71238898038 //3*PI/2
# define DR 0.0174533
# define WIDTH 1920
# define HEIGHT 980

# define SQUARE_SIZE 64

# define STEP_SIZE 5

# define PLAYER_SIZE 20
# define PLAYER_BUFFER_SIZE 1
# define OBSTACLE_COLOR 0x000000


typedef enum e_exit
{
	FAILURE,
	SUCCESS,
}	t_exit;

//--------- calculations -------
typedef struct s_intersection_vars
{
	float	rx;
	float	ry;
	float	xo;
	float	yo;
}	t_intersection_vars;

typedef struct s_ray_vars
{
	float	rx;
	float	ry;
	float	hx;
	float	hy;
	float	vx;
	float	vy;
	float	line_h;
	float	line_v;
}	t_ray_vars;
//--------- ------------ -------

typedef struct s_map
{
	int					width;
	int					height;
	char				**coord;
}	t_map;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_player
{
	float	player_x;
	float	player_y;
	float	player_delta_x;
	float	player_delta_y;
	float	player_angle;
}	t_player;

typedef struct s_mlx
{
	void		*mlx_connect;
	void		*mlx_win;
	t_player	*player;
	t_map		*map;
	t_img		img;
}	t_mlx;

// --------------- main.c ------------------------- //

int		main(void);
void	ft_bresenhams_alg(t_mlx *win, float end_x, float end_y, int color);

// --------------- img_create.c ------------------ //

void	my_pixel_put(t_img *img, int x, int y, int color);
void	render_background(t_img *img, int color);

// --------------- events.c --------------------- //

void	ft_cleanup_and_exit(t_mlx *mlx);
int		ft_close(t_mlx *mlx);
int		ft_event_checker(int Key, t_mlx *mlx);
int		arrow_keys(int Key, t_mlx *mlx);

// --------------- draw_shapes.c ---------------- //

void	ft_update_player(int px, int py, t_img *img, t_mlx *win);
void	ft_draw_map(t_map *map, t_img *img, t_mlx *win);
void	draw_square(t_img *img, int x, int y, int color);

// --------------- utils.c --------------------- //

int		ft_mod(int n);
void	set_up_win(t_mlx *win, char **map);
float	line_length(float x1, float y1, float x2, float y2);

// --------------- raycast.c --------------------- //

void	raycaster(t_mlx *win);
void	get_horizontal_intersection(t_mlx *win, float ra, float *hx, float *hy);
void	get_vertical_intersection(t_mlx *win, float ra, float *vx, float *vy);

#endif
