/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kro <kro@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:41:16 by hbaduel           #+#    #+#             */
/*   Updated: 2023/12/13 12:39:35 by kro              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	get_pixel_color(t_texture *img, int x, int y)
{
	int	color;

	color = *(unsigned int *)(img->img_data + (y * img->size_line + x * \
	(img->bpp / 8)));
	return (color);
}

void	ft_drawdirection(t_mlx *mlx, t_texture *img, int ray_nb, int x)
{
	int		i;
	int		color;
	int		y;
	double	ratio;
	double	diff;

	i = 0;
	img->hp = floor(ft_height_projected(mlx));
	img->wall_pos = floor(ft_top_wall_position(&img->hp));
	ratio = 1 - ((1 - img->hp / floor(ft_height_projected(mlx))) / 2);
	diff = img->hp / floor(ft_height_projected(mlx)) / img->hp;
	while (i < img->wall_pos)
		mlx_pix_put(mlx, ray_nb, i++, create_trgb(0, \
		mlx->data->ceiling[0], mlx->data->ceiling[1], mlx->data->ceiling[2]));
	while (img->hp-- >= 0)
	{
		y = XPM_SIZE - ratio * XPM_SIZE;
		ratio -= diff;
		color = get_pixel_color(img, x, y);
		mlx_pix_put(mlx, ray_nb, i++, color);
	}
	while (i < HEIGHT)
		mlx_pix_put(mlx, ray_nb, i++, create_trgb(0, \
		mlx->data->floor[0], mlx->data->floor[1], mlx->data->floor[2]));
}

void	draw_column(t_mlx *mlx, int ray_nb)
{
	if (mlx->ray->wall == 'N')
		ft_drawdirection(mlx, mlx->data->north, ray_nb, \
		(int)(mlx->ray->wx) % XPM_SIZE);
	else if (mlx->ray->wall == 'S')
		ft_drawdirection(mlx, mlx->data->south, ray_nb, \
		(int)(mlx->ray->wx) % XPM_SIZE);
	else if (mlx->ray->wall == 'E')
		ft_drawdirection(mlx, mlx->data->east, ray_nb, \
		(int)(mlx->ray->wy) % XPM_SIZE);
	else if (mlx->ray->wall == 'W')
		ft_drawdirection(mlx, mlx->data->west, ray_nb, \
		(int)(mlx->ray->wy) % XPM_SIZE);
}
