/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kro <kro@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:00:18 by hbaduel           #+#    #+#             */
/*   Updated: 2023/12/13 12:39:53 by kro              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	mlx_pix_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->img_data + (y * mlx->size_line + x * (mlx->bpp / 8));
	*(unsigned int *)dst = color;
}

double	ft_height_projected(t_mlx *mlx)
{
	double	height_projected;

	height_projected = XPM_SIZE / mlx->ray->dist * (277 * 4);
	return (height_projected);
}

double	ft_top_wall_position(int *height_projected)
{
	double	top_wall_position;

	top_wall_position = (HEIGHT / 2) - (*height_projected / 2);
	if (top_wall_position < 0)
		*height_projected += top_wall_position * 2;
	return (top_wall_position);
}

void	ft_crosshair(t_mlx *mlx)
{
	int	color;
	int	temp;

	color = create_trgb(0, 255, 255, 255);
	temp = WIDTH / 2 - 5;
	while (temp <= WIDTH / 2 + 5)
	{
		mlx_pix_put(mlx, temp, HEIGHT / 2, color);
		mlx_pix_put(mlx, temp, HEIGHT / 2 + 1, color);
		mlx_pix_put(mlx, temp, HEIGHT / 2 - 1, color);
		temp++;
	}
	temp = HEIGHT / 2 - 5;
	while (temp <= HEIGHT / 2 + 5)
	{
		mlx_pix_put(mlx, WIDTH / 2, temp, color);
		mlx_pix_put(mlx, WIDTH / 2 + 1, temp, color);
		mlx_pix_put(mlx, WIDTH / 2 - 1, temp, color);
		temp++;
	}
}

int	render(t_mlx *mlx)
{
	ft_castfov(mlx);
	if (mlx->start->crosshair == 1)
		ft_crosshair(mlx);
	if (mlx->start->minimap == 1)
		ft_minimap(mlx, (int)mlx->player->posy / XPM_SIZE, \
		(int)mlx->player->posx / XPM_SIZE);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}
