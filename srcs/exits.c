/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kro <kro@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:49:17 by hbaduel           #+#    #+#             */
/*   Updated: 2023/12/13 13:09:37 by kro              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_exitgame(t_mlx *mlx)
{
	int	i;

	i = 0;
	ft_putstr("\n\n\t\tYou have left the game \U0001F622\n\n\n");
	mlx_loop_end(mlx->mlx);
	mlx_destroy_window(mlx->mlx, mlx->win);
	ft_freewall(mlx, mlx->data, 4, mlx->data->map);
	ft_freestart(mlx, mlx->start, 7);
	mlx_destroy_image(mlx->mlx, mlx->img);
	while (mlx->data->map[i])
	{
		free(mlx->data->map[i]);
		i++;
	}
	free(mlx->data->map);
	free(mlx->data);
	free(mlx->player);
	free(mlx->start);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	free(mlx);
	exit(0);
}

void	ft_exitreadfile(t_mlx *mlx, char *str, int code)
{
	ft_freewall(mlx, mlx->data, code, mlx->data->map);
	ft_freestart(mlx, mlx->start, 7);
	ft_free_strarr(mlx->data->map);
	free(mlx->data);
	free(mlx->player);
	free(mlx->start);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	free(mlx);
	ft_putstr(str);
	exit(1);
}

void	ft_exitstart(t_mlx *mlx, int code)
{
	if (code != 7)
		ft_putstr("ERROR : Starting screen's asset(s) missing\n");
	ft_freestart(mlx, mlx->start, code);
	free(mlx->data);
	free(mlx->player);
	free(mlx->start);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	free(mlx);
	exit(1);
}
