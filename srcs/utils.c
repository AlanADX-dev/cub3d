/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaduel <hbaduel@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:43:04 by hbaduel           #+#    #+#             */
/*   Updated: 2023/12/12 23:44:37 by hbaduel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_strarrlen(char **strarr)
{
	int	size;

	size = 0;
	while (strarr[size])
		size++;
	return (size);
}

double	ft_correctdist(double dist, double dir, double ray)
{
	double	correct;
	double	beta;

	beta = ray - dir;
	correct = dist * cos((beta * (double)PI) / (double)180);
	return (correct);
}

double	ft_searchnewpoint(double pos, double diff)
{
	modf(pos, &pos);
	while ((int)pos % XPM_SIZE != 0)
	{
		if (diff > 0)
			pos += 1;
		else
			pos -= 1;
	}
	return (pos);
}

void	ft_setrayinf(t_ray *ray, t_player *p, int x, int y)
{
	ray->wx = x;
	ray->wy = y;
	ray->dist = sqrt(pow(p->posx - x, 2) + pow(p->posy - y, 2));
}

void	ft_free_strarr(char **strarr)
{
	int	i;

	if (strarr)
	{
		i = 0;
		while (strarr[i])
		{
			free(strarr[i]);
			i++;
		}
		free(strarr);
	}
}
