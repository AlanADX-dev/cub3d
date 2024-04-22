/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaduel <hbaduel@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:50:01 by hbaduel           #+#    #+#             */
/*   Updated: 2023/12/13 12:16:15 by hbaduel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_checkidentifier(t_mlx *mlx, char **map)
{
	int	*id;
	int	i;

	id = ft_calloc(7, sizeof(int));
	i = 0;
	while (i < 6)
	{
		if (ft_strncmp("NO", map[i], 2) == 0)
			id[0]++;
		else if (ft_strncmp("SO", map[i], 2) == 0)
			id[1]++;
		else if (ft_strncmp("WE", map[i], 2) == 0)
			id[2]++;
		else if (ft_strncmp("EA", map[i], 2) == 0)
			id[3]++;
		else if (ft_strncmp("F", map[i], 1) == 0)
			id[4]++;
		else if (ft_strncmp("C", map[i], 1) == 0)
			id[5]++;
		else
			id[6]++;
		i++;
	}
	ft_checktabid(mlx, id);
}

void	ft_checkaround(t_mlx *mlx, char **map, int i, int j)
{
	int	k;
	int	res;
	int	size;

	k = i - 1;
	res = 0;
	while (k >= 0)
	{
		if (ft_strlen(map[k]) > j && map[k][j] == '1')
			res = 1;
		k--;
	}
	if (res == 0)
		ft_exitreadfile(mlx, "ERROR: Map not closed\n", 4);
	res = 0;
	k = i + 1;
	size = ft_strarrlen(map);
	while (k < size)
	{
		if (ft_strlen(map[k]) > j && map[k][j] == '1')
			res = 1;
		k++;
	}
	if (res == 0)
		ft_exitreadfile(mlx, "ERROR: Map not closed\n", 4);
}

void	ft_checkcolumnclose(t_mlx	*mlx, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '\t' && map[i][j] != ' ')
				ft_checkaround(mlx, map, i, j);
			j++;
		}
		i++;
	}
}

void	ft_checklignclose(t_mlx	*mlx, char **map)
{
	int	iswall;
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		iswall = 0;
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				iswall = 1;
			else if (map[i][j] == ' ' || map[i][j] == '\t')
				iswall = 0;
			else if (map[i][j] != '1' && map[i][j] != ' ' && \
			map[i][j] != '\t' && iswall == 0)
				ft_exitreadfile(mlx, "ERROR: Map not closed\n", 4);
			j++;
		}
		if (map[i][j - 1] != '1' && map[i][j - 1] != ' ' && \
		map[i][j - 1] != '\t')
			ft_exitreadfile(mlx, "ERROR: Map not closed\n", 4);
		i++;
	}
}

void	ft_checkcontent(t_mlx *mlx, char **map)
{
	int	nplayer;
	int	i;
	int	j;

	i = 0;
	nplayer = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || \
			map[i][j] == 'E' || map[i][j] == 'W')
				nplayer++;
			else if (map[i][j] != '0' && map[i][j] != '1' && \
			map[i][j] != ' ' && map[i][j] != '\t')
				ft_exitreadfile(mlx, \
				"ERROR: a character in the map is not valid\n", 4);
			j++;
		}
		i++;
	}
	if (nplayer != 1)
		ft_exitreadfile(mlx, "ERROR: Invalid number of player\n", 4);
}
