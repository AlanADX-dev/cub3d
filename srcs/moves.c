/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kro <kro@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:34:14 by hbaduel           #+#    #+#             */
/*   Updated: 2023/12/14 13:49:15 by kro              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_forwardcheck(t_player *player, char **map)
{
	if (ft_movecheck(map, player->posx - cos(player->angle * PI / 180) * \
	(MOVESIZE * 3), player->posy - sin(player->angle * PI / 180) \
	* (MOVESIZE * 3)) == 1)
		return (1);
	if (ft_movecheck(map, player->posx - cos((player->angle - 15) * PI / 180) \
	* (MOVESIZE * 3), player->posy - sin((player->angle - 15) * PI / 180) \
	* (MOVESIZE * 3)) == 1)
		return (1);
	if (ft_movecheck(map, player->posx - cos((player->angle + 15) * PI / 180) \
	* (MOVESIZE * 3), player->posy - sin((player->angle + 15) * PI / 180) \
	* (MOVESIZE * 3)) == 1)
		return (1);
	return (0);
}

int	ft_backcheck(t_player *player, char **map)
{
	if (ft_movecheck(map, player->posx + cos(player->angle * PI / 180) * \
	(MOVESIZE * 3), player->posy + sin(player->angle * PI / 180) \
	* (MOVESIZE * 3)) == 1)
		return (1);
	if (ft_movecheck(map, player->posx + cos((player->angle - 15) * PI / 180) \
	* (MOVESIZE * 3), player->posy + sin((player->angle - 15) * PI / 180) \
	* (MOVESIZE * 3)) == 1)
		return (1);
	if (ft_movecheck(map, player->posx + cos((player->angle + 15) * PI / 180) \
	* (MOVESIZE * 3), player->posy + sin((player->angle + 15) * PI / 180) \
	* (MOVESIZE * 3)) == 1)
		return (1);
	return (0);
}

void	ft_anglemove(int keysym, t_mlx *mlx)
{
	if (keysym == XK_a)
	{
		mlx->player->angle -= ANGLEMOVE;
		if (mlx->player->angle < 0)
			mlx->player->angle = 360 + mlx->player->angle;
	}
	if (keysym == XK_d)
	{
		mlx->player->angle += ANGLEMOVE;
		if (mlx->player->angle >= 360)
			mlx->player->angle = mlx->player->angle - 360;
	}
}

int	handle_keypress(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
		ft_exitgame(mlx);
	if (keysym == XK_w || keysym == XK_Up)
	{
		if (ft_forwardcheck(mlx->player, mlx->data->map) == 0)
		{
			mlx->player->posx -= cos(mlx->player->angle * PI / 180) * MOVESIZE;
			mlx->player->posy -= sin(mlx->player->angle * PI / 180) * MOVESIZE;
		}
	}
	if (keysym == XK_s)
	{
		if (ft_backcheck(mlx->player, mlx->data->map) == 0)
		{
			mlx->player->posx += cos(mlx->player->angle * PI / 180) * MOVESIZE;
			mlx->player->posy += sin(mlx->player->angle * PI / 180) * MOVESIZE;
		}
	}
	ft_anglemove(keysym, mlx);
	return (0);
}

int	ft_movemouse(int x, int y, t_mlx *mlx)
{
	(void)y;
	if (mlx->start->start == 1)
	{
		mlx->player->angle += (double)((x - 640) * SPEEDMOUSE);
		if (mlx->player->angle < 0)
			mlx->player->angle = 360 + mlx->player->angle;
		else if (mlx->player->angle >= 360)
			mlx->player->angle = mlx->player->angle - 360;
		mlx_mouse_move(mlx->mlx, mlx->win, 640, 400);
	}
	return (0);
}
