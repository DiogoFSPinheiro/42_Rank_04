/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:56:41 by diogosan          #+#    #+#             */
/*   Updated: 2024/11/06 18:00:56 by diogosan         ###   ########.fr       */
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

# define WIDTH 1920
# define HEIGHT 980

# define SQUARE_SIZE 50

# define STEP_SIZE 5

# define PLAYER_SIZE 20
# define PLAYER_BUFFER_SIZE 1
# define OBSTACLE_COLOR 0x000000

/*typedef struct s_point
{
	float				x;
	float				y;
	int					z;
	int					color;
}	t_point;*/

typedef enum e_exit
{
	FAILURE,
	SUCCESS,
}	t_exit;


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

typedef struct s_mlx
{
	void	*mlx_connect;
	void	*mlx_win;
	int		posx;
	int		posy;
	int		player_x;
	int		player_y;
	t_map	*map;
	t_img	img;
}	t_mlx;

// --------------- main.c ------------------------- //

int		main(void);

// --------------- img_create.c ------------------ //

void	my_pixel_put(t_img *img, int x, int y, int color);
void	render_background(t_img *img, int color);

// --------------- events.c --------------------- //

void	ft_cleanup_and_exit(t_mlx *mlx);
int		ft_close(t_mlx *mlx);
int		ft_event_checker(int Key, t_mlx *mlx);
int		arrow_keys(int Key, t_mlx *mlx);

#endif
