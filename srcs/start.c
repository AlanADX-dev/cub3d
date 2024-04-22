/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaduel <hbaduel@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:46:03 by hbaduel           #+#    #+#             */
/*   Updated: 2023/12/07 19:28:36 by hbaduel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	start_keypress(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
		ft_exitgame(mlx);
	return (0);
}

void	settings_mouse(int mouse, int x, int y, t_mlx *mlx)
{
	(void)mouse;
	if ((x >= 17 && x <= 63) && (y >= 18 && y <= 60))
	{
		mlx->start->settings = 0;
		mlx->start->frame = 0;
	}
	if ((x >= 790 && x <= 854) && (y >= 375 && y <= 425))
		mlx->start->minimap *= -1;
	if ((x >= 790 && x <= 854) && (y >= 575 && y <= 625))
		mlx->start->crosshair *= -1;
}

/*mlx_mouse_hide(mlx->mlx, mlx->win);*/

int	start_mouse(int mouse, int x, int y, t_mlx *mlx)
{
	if (mouse == 1 && mlx->start->settings == 0)
	{
		if ((x >= 1170 && x <= 1238) && (y >= 45 && y <= 112))
			mlx->start->settings = 1;
		if ((x >= 527 && x <= 755) && (y >= 415 && y <= 503) \
		&& mlx->start->settings == 0)
		{
			mlx->start->start = 1;
			mlx_mouse_move(mlx->mlx, mlx->win, 640, 400);
			mlx_hook(mlx->win, KeyPress, KeyPressMask, handle_keypress, mlx);
			mlx_hook(mlx->win, 17, 1L << 0, ft_exitgame, mlx);
			mlx_mouse_hook(mlx->win, NULL, NULL);
			mlx_loop_hook(mlx->mlx, render, mlx);
		}
	}
	else if (mouse == 1 && mlx->start->settings == 1)
		settings_mouse(mouse, x, y, mlx);
	return (0);
}

void	ft_startingsettings(t_mlx *mlx)
{
	if (mlx->start->minimap == 1 && mlx->start->crosshair == 1)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->start->set11, 0, 0);
	else if (mlx->start->minimap == -1 && mlx->start->crosshair == 1)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->start->set01, 0, 0);
	else if (mlx->start->minimap == 1 && mlx->start->crosshair == -1)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->start->set10, 0, 0);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->start->set00, 0, 0);
}

int	ft_startingscreen(t_mlx *mlx)
{
	if (mlx->start->settings == 0)
	{
		if (mlx->start->frame == 40000)
			mlx->start->frame = 0;
		if (mlx->start->frame == 0)
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->start->bg1, 0, 0);
		else if (mlx->start->frame == 10000)
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->start->bg2, 0, 0);
		else if (mlx->start->frame == 20000)
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->start->bg3, 0, 0);
		else if (mlx->start->frame == 30000)
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->start->bg2, 0, 0);
		mlx->start->frame++;
	}
	else
		ft_startingsettings(mlx);
	return (0);
}
