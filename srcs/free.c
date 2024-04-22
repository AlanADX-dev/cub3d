/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaduel <hbaduel@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:49:37 by hbaduel           #+#    #+#             */
/*   Updated: 2023/12/13 12:05:20 by hbaduel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_freestart(t_mlx *mlx, t_start *start, int code)
{
	if (code == 0)
		return ;
	mlx_destroy_image(mlx->mlx, start->bg1);
	if (code == 1)
		return ;
	mlx_destroy_image(mlx->mlx, start->bg2);
	if (code == 2)
		return ;
	mlx_destroy_image(mlx->mlx, start->bg3);
	if (code == 3)
		return ;
	mlx_destroy_image(mlx->mlx, start->set11);
	if (code == 4)
		return ;
	mlx_destroy_image(mlx->mlx, start->set10);
	if (code == 5)
		return ;
	mlx_destroy_image(mlx->mlx, start->set01);
	if (code == 6)
		return ;
	mlx_destroy_image(mlx->mlx, start->set00);
}

int	ft_cmpall(t_data *data, char *map, t_texture **temp)
{
	if (ft_strncmp("NO", map, 2) == 0)
	{
		*temp = data->north;
		return (1);
	}
	else if (ft_strncmp("SO", map, 2) == 0)
	{
		*temp = data->south;
		return (1);
	}
	else if (ft_strncmp("WE", map, 2) == 0)
	{
		*temp = data->west;
		return (1);
	}
	else if (ft_strncmp("EA", map, 2) == 0)
	{
		*temp = data->east;
		return (1);
	}
	return (0);
}

char	**ft_whichwall(t_data *data, char **map, t_texture **temp)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_cmpall(data, map[i], temp) == 1)
			break ;
		i++;
	}
	return (&map[i + 1]);
}

void	ft_freeallwall(t_mlx *mlx, t_data *data, int code)
{
	if (code == 0)
		return ;
	mlx_destroy_image(mlx->mlx, data->north->img_ptr);
	free(mlx->data->north);
	mlx_destroy_image(mlx->mlx, data->south->img_ptr);
	free(mlx->data->south);
	mlx_destroy_image(mlx->mlx, data->west->img_ptr);
	free(mlx->data->west);
	mlx_destroy_image(mlx->mlx, data->east->img_ptr);
	free(mlx->data->east);
}

void	ft_freewall(t_mlx *mlx, t_data *data, int code, char **map)
{
	t_texture	*temp;

	if (code == 0 || code == 4)
	{
		ft_freeallwall(mlx, data, code);
		return ;
	}
	map = ft_whichwall(data, map, &temp);
	mlx_destroy_image(mlx->mlx, temp->img_ptr);
	free(temp);
	if (code == 1)
		return ;
	map = ft_whichwall(data, map, &temp);
	mlx_destroy_image(mlx->mlx, temp->img_ptr);
	free(temp);
	if (code == 2)
		return ;
	map = ft_whichwall(data, map, &temp);
	mlx_destroy_image(mlx->mlx, temp->img_ptr);
	free(temp);
	if (code == 3)
		return ;
	map = ft_whichwall(data, map, &temp);
	mlx_destroy_image(mlx->mlx, temp->img_ptr);
	free(temp);
}
