/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:56:41 by diogosan          #+#    #+#             */
/*   Updated: 2024/11/04 16:25:42 by diogosan         ###   ########.fr       */
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
# define HEIGHT 1080

typedef struct s_point
{
	float				x;
	float				y;
	int					z;
	int					color;
}	t_point;

typedef struct s_map
{
	int					width;
	int					height;
	t_point				**coord;
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
	t_map	*map;
	int		zoom;
	float	z_zoom;
	int		shift_x;
	int		shift_y;
	float	view;
	float	c_factor;
	t_img	img;
}	t_mlx;

int	main(void);

#endif
