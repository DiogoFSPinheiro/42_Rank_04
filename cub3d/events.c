/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:32:11 by diogosan          #+#    #+#             */
/*   Updated: 2024/11/05 12:14:52 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libraries/printf/ft_printf.h"


void	ft_cleanup_and_exit(t_mlx *mlx)
{
	if (mlx->mlx_connect != NULL)
	{
		mlx_destroy_image(mlx->mlx_connect, mlx->img.mlx_img);
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

int	ft_event_checker(int Key, t_mlx *mlx)
{
	if (Key == XK_Escape)
		ft_cleanup_and_exit(mlx);
	return (0);
}

int	arrow_keys(int Key, t_mlx *mlx)
{
	(void)mlx;
	if (Key == XK_Right)
	{
		mlx->posx += 5;
		ft_println("moved right");
	}
	if (Key == XK_Left)
	{
		mlx->posx -= 5;
		ft_println("moved left");
	}
	if (Key == XK_Up)
	{
		mlx->posy -= 5;
		ft_println("moved front");
	}
	if (Key == XK_Down)
	{
		mlx->posy += 5;
		ft_println("moved back");
	}
	if (Key == XK_equal)
		;
	if (Key == XK_minus)
		;
	if (Key == XK_z)
		;
	if (Key == XK_x)
		;
	return (0);
}
