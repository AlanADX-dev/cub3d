/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaduel <hbaduel@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:17:15 by hbaduel           #+#    #+#             */
/*   Updated: 2023/12/07 11:53:44 by hbaduel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_vercheck(char **map, double x, double y)
{
	int	i;
	int	j;

	i = (int)(y / XPM_SIZE);
	j = (int)(x / XPM_SIZE);
	if (i < 0 || i >= ft_strarrlen(map))
		return (1);
	if (j < 0 || j >= ft_strlen(map[i]))
		return (1);
	if (map[i][j] == '1' || map[i][j] == ' ' || map[i][j] == '\t')
		return (1);
	if (j - 1 < 0)
		return (1);
	if (map[i][j - 1] == '1' || map[i][j - 1] == ' ' || map[i][j - 1] == '\t')
		return (1);
	return (0);
}

int	ft_horcheck(char **map, double x, double y)
{
	int	i;
	int	j;

	i = (int)(y / XPM_SIZE);
	j = (int)(x / XPM_SIZE);
	if (i < 0 || i >= ft_strarrlen(map))
		return (1);
	if (j < 0 || j >= ft_strlen(map[i]))
		return (1);
	if (map[i][j] == '1' || map[i][j] == ' ' || map[i][j] == '\t')
		return (1);
	if (i - 1 < 0)
		return (1);
	if (map[i - 1][j] == '1' || map[i - 1][j] == ' ' || map[i - 1][j] == '\t')
		return (1);
	return (0);
}

void	ft_verticalsearch(t_player *p, t_ray *ray, double angle, char **map)
{
	double	newx;
	double	newy;
	double	ya;
	double	xa;

	if (angle >= 90 && angle <= 270)
		xa = (double)XPM_SIZE;
	else
		xa = (double)-XPM_SIZE;
	newx = ft_searchnewpoint(p->posx, xa);
	newy = (newx - p->posx) * tan(angle * PI / 180) + p->posy;
	ya = xa * tan((angle * (double)PI) / (double)180);
	while (1)
	{
		if (ft_vercheck(map, newx, newy) == 1)
			break ;
		newx += xa;
		newy += ya;
	}
	ft_setrayinf(ray, p, newx, newy);
	if (angle >= 90 && angle <= 270)
		ray->wall = 'E';
	else
		ray->wall = 'W';
}

void	ft_horizontalsearch(t_player *p, t_ray *ray, double angle, char **map)
{
	double	newx;
	double	newy;
	double	ya;
	double	xa;

	if (angle >= 0 && angle <= 180)
		ya = (double)-XPM_SIZE;
	else
		ya = (double)XPM_SIZE;
	newy = ft_searchnewpoint(p->posy, ya);
	newx = (newy - p->posy) / tan(angle * PI / 180) + p->posx;
	xa = ya / tan((angle * (double)PI) / (double)180);
	while (1)
	{
		if (ft_horcheck(map, newx, newy) == 1)
			break ;
		newy += ya;
		newx += xa;
	}
	ft_setrayinf(ray, p, newx, newy);
	if (angle >= 0 && angle <= 180)
		ray->wall = 'N';
	else
		ray->wall = 'S';
}

t_ray	*ft_searchwall(t_player *player, double angle, char **map)
{
	t_ray	*hor;
	t_ray	*ver;

	hor = malloc(sizeof(t_ray));
	ver = malloc(sizeof(t_ray));
	ft_horizontalsearch(player, hor, angle, map);
	ft_verticalsearch(player, ver, angle, map);
	if (hor->dist <= ver->dist)
	{
		free(ver);
		return (hor);
	}
	else
	{
		free(hor);
		return (ver);
	}
}
