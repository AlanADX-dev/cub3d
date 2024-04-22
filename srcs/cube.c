/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaduel <hbaduel@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:04:22 by hbaduel           #+#    #+#             */
/*   Updated: 2023/12/12 23:19:31 by hbaduel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_castfov(t_mlx *mlx)
{
	int		nray;
	double	start;

	start = mlx->player->angle - FOV / 2;
	if (start < 0)
		start = 360 + start;
	nray = 0;
	while (nray <= WIDTH)
	{
		mlx->ray = ft_searchwall(mlx->player, start, mlx->data->map);
		mlx->ray->dist = \
		ft_correctdist(mlx->ray->dist, mlx->player->angle, start);
		draw_column(mlx, nray);
		free(mlx->ray);
		start += (double)FOV / (double)WIDTH;
		if (start >= 360)
			start = 360 - start;
		nray++;
	}
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc != 2)
	{
		ft_putstr("\nERROR :\n\tUsage = ./cub3d map/\"mapname.cub\".\n\n");
		exit(1);
	}
	mlx = malloc(sizeof(t_mlx));
	ft_set_structs(mlx, argv[1]);
	ft_readmap(mlx, mlx->data->map);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Cub3gay!");
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->img_data = mlx_get_data_addr(mlx->img, &mlx->bpp, \
	&mlx->size_line, &mlx->endian);
	mlx_hook(mlx->win, MotionNotify, PointerMotionMask, ft_movemouse, mlx);
	mlx_hook(mlx->win, DestroyNotify, KeyPressMask, ft_exitgame, mlx);
	mlx_hook(mlx->win, KeyPress, KeyPressMask, start_keypress, mlx);
	mlx_mouse_hook(mlx->win, start_mouse, mlx);
	mlx_loop_hook(mlx->mlx, ft_startingscreen, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
