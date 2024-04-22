/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaduel <hbaduel@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:03:37 by hbaduel           #+#    #+#             */
/*   Updated: 2023/12/11 11:42:29 by hbaduel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_openimgsettings(t_mlx *mlx)
{
	int	x;
	int	y;

	mlx->start->set11 = mlx_xpm_file_to_image(mlx->mlx, \
	"sprites/set11.xpm", &x, &y);
	if (!mlx->start->set11)
		ft_exitstart(mlx, 3);
	mlx->start->set01 = mlx_xpm_file_to_image(mlx->mlx, \
	"sprites/set01.xpm", &x, &y);
	if (!mlx->start->set01)
		ft_exitstart(mlx, 4);
	mlx->start->set10 = mlx_xpm_file_to_image(mlx->mlx, \
	"sprites/set10.xpm", &x, &y);
	if (!mlx->start->set10)
		ft_exitstart(mlx, 5);
	mlx->start->set00 = mlx_xpm_file_to_image(mlx->mlx, \
	"sprites/set00.xpm", &x, &y);
	if (!mlx->start->set00)
		ft_exitstart(mlx, 6);
}

void	ft_openimgbonus(t_mlx *mlx)
{
	int	x;
	int	y;

	mlx->start->bg1 = mlx_xpm_file_to_image(mlx->mlx, \
	"sprites/bg1.xpm", &x, &y);
	if (!mlx->start->bg1)
		ft_exitstart(mlx, 0);
	mlx->start->bg2 = mlx_xpm_file_to_image(mlx->mlx, \
	"sprites/bg2.xpm", &x, &y);
	if (!mlx->start->bg2)
		ft_exitstart(mlx, 1);
	mlx->start->bg3 = mlx_xpm_file_to_image(mlx->mlx, \
	"sprites/bg3.xpm", &x, &y);
	if (!mlx->start->bg3)
		ft_exitstart(mlx, 2);
	ft_openimgsettings(mlx);
}

void	ft_set_structs(t_mlx *mlx, char *filename)
{
	mlx->data = malloc(sizeof(t_data));
	mlx->player = malloc(sizeof(t_player));
	mlx->start = malloc(sizeof(t_start));
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
	{
		free(mlx->player);
		free(mlx->data);
		free(mlx->start);
		free(mlx);
		ft_putstr("ERROR : Mlx init error\n");
		exit(1);
	}
	mlx->start->frame = 0;
	mlx->start->crosshair = 1;
	mlx->start->minimap = 1;
	mlx->start->settings = 0;
	mlx->start->start = 0;
	ft_openimgbonus(mlx);
	ft_splitfile(mlx, ft_readfile(mlx, filename));
}

void	ft_setinformation(t_mlx *mlx, char c, int i, int j)
{
	mlx->player->posx = ((double)j + 0.5) * XPM_SIZE;
	mlx->player->posy = ((double)i + 0.5) * XPM_SIZE;
	mlx->bpp = 8;
	mlx->size_line = ((256 * mlx->bpp + 63) / 64) * 4;
	if (c == 'N')
		mlx->player->angle = 90;
	else if (c == 'E')
		mlx->player->angle = 180;
	else if (c == 'S')
		mlx->player->angle = 270;
	else if (c == 'W')
		mlx->player->angle = 0;
}

void	ft_readmap(t_mlx *mlx, char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || \
			map[i][j] == 'W' || map[i][j] == 'E')
			{
				ft_setinformation(mlx, map[i][j], i, j);
				return ;
			}
			j++;
		}
		i++;
	}
}
