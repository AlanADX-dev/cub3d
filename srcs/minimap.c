/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaduel <hbaduel@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:14:02 by hbaduel           #+#    #+#             */
/*   Updated: 2023/12/07 14:24:58 by hbaduel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_drawline(t_mlx *mlx, int color, int miniposx, int miniposy)
{
	double	angle;
	double	length;
	double	t;

	length = XPM_SIZE / 20;
	angle = -mlx->player->angle - FOV / 2;
	t = 0.01;
	while (t < 1.0)
	{
		mlx_pix_put(mlx, miniposx - t * (miniposx + length * \
		cos(angle * PI / 180) - miniposx), miniposy + t * (miniposy + length \
		* sin(angle * PI / 180) - miniposy), color);
		t += 0.01;
	}
	angle = -mlx->player->angle + FOV / 2;
	t = 0.01;
	while (t < 1.0)
	{
		mlx_pix_put(mlx, miniposx - t * (miniposx + length * \
		cos(angle * PI / 180) - miniposx), miniposy + t * (miniposy + length \
		* sin(angle * PI / 180) - miniposy), color);
		t += 0.01;
	}
}

void	ft_drawcontour(t_mlx *mlx)
{
	int	color;
	int	x;
	int	y;

	color = create_trgb(0, 255, 255, 255);
	x = 16;
	while (x < 160)
	{
		ft_drawsquare4(mlx, x, 16, color);
		ft_drawsquare4(mlx, x, 160, color);
		x += 4;
	}
	y = 20;
	while (y < 160)
	{
		ft_drawsquare4(mlx, 16, y, color);
		ft_drawsquare4(mlx, x - 4, y, color);
		y += 4;
	}
}

void	ft_drawplayer(t_mlx *mlx)
{
	double	temp;
	double	miniposx;
	double	miniposy;

	modf(mlx->player->posx / XPM_SIZE, &temp);
	miniposx = 78 + 16 * (mlx->player->posx / XPM_SIZE - temp);
	modf(mlx->player->posy / XPM_SIZE, &temp);
	miniposy = 78 + 16 * (mlx->player->posy / XPM_SIZE - temp);
	ft_drawline(mlx, create_trgb(0, 255, 255, 255), miniposx + 2, miniposy + 2);
	ft_drawsquare4(mlx, (int)miniposx, (int)miniposy, \
	create_trgb(0, 114, 214, 206));
	ft_drawcontour(mlx);
}

void	ft_drawminimap(t_mlx *mlx, char c, int x, int y)
{
	if (c == ' ')
		ft_drawsquare16(mlx, x, y, create_trgb(0, 37, 19, 26));
	else if (c == '1')
		ft_drawsquare16(mlx, x, y, create_trgb(0, 184, 184, 184));
	else
		ft_drawsquare16(mlx, x, y, create_trgb(0, 46, 51, 87));
}

void	ft_minimap(t_mlx *mlx, int ip, int jp)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = ip - 4;
	y = 16;
	while (i <= ip + 4)
	{
		x = 16;
		j = jp - 4;
		while (j <= jp + 4)
		{
			if ((i >= 0 && i < ft_strarrlen(mlx->data->map)) && (j >= 0 && \
			j < ft_strlen(mlx->data->map[i])))
				ft_drawminimap(mlx, mlx->data->map[i][j], x, y);
			else
				ft_drawsquare16(mlx, x, y, create_trgb(0, 37, 19, 26));
			j++;
			x += 16;
		}
		y += 16;
		i++;
	}
	ft_drawplayer(mlx);
}
