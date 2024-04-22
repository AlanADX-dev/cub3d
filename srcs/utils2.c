/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaduel <hbaduel@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:13:38 by hbaduel           #+#    #+#             */
/*   Updated: 2023/12/13 12:17:11 by hbaduel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_movecheck(char **map, double X, double Y)
{
	int	i;
	int	j;

	i = (int)ceil(Y) / XPM_SIZE;
	j = (int)ceil(X) / XPM_SIZE;
	if (i < 0 || i >= ft_strarrlen(map))
		return (1);
	if (j < 0 || j >= ft_strlen(map[i]))
		return (1);
	if (map[i][j] == '1' || map[i][j] == ' ' || map[i][j] == '\t')
		return (1);
	return (0);
}

void	ft_drawsquare16(t_mlx *mlx, int x, int y, int color)
{
	int	temp;
	int	xmax;
	int	ymax;

	xmax = x + 16;
	ymax = y + 16;
	temp = x;
	while (y < ymax)
	{
		x = temp;
		while (x < xmax)
		{
			mlx_pix_put(mlx, x, y, color);
			x++;
		}
		y++;
	}
}

void	ft_drawsquare4(t_mlx *mlx, int x, int y, int color)
{
	int	temp;
	int	xmax;
	int	ymax;

	xmax = x + 4;
	ymax = y + 4;
	temp = x;
	while (y < ymax)
	{
		x = temp;
		while (x < xmax)
		{
			mlx_pix_put(mlx, x, y, color);
			x++;
		}
		y++;
	}
}

void	ft_checktabid(t_mlx *mlx, int *id)
{
	int	i;

	i = 0;
	if (id[6] != 0)
	{
		free(id);
		ft_exitreadfile(mlx, "ERROR: Bad identifier\n", 0);
	}
	while (i < 6)
	{
		if (id[i] == 0)
		{
			free(id);
			ft_exitreadfile(mlx, "ERROR: Missing/Bad identifier\n", 0);
		}
		else if (id[i] > 1)
		{
			free(id);
			ft_exitreadfile(mlx, "ERROR: Double identifier\n", 0);
		}
		i++;
	}
	free(id);
}
