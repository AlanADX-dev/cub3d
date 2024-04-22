/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaduel <hbaduel@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:00:55 by hbaduel           #+#    #+#             */
/*   Updated: 2023/12/13 00:13:05 by hbaduel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	create_trgb(unsigned int t, unsigned int r, unsigned int g, unsigned int b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

int	ft_checkrgb(char *line)
{
	int	i;
	int	ncomma;
	int	max;

	max = 0;
	while ((line[max] != ' ' || line[max] != '\t') && line[max])
		max++;
	i = 0;
	ncomma = 0;
	while (i < max)
	{
		if (line[i] == ',')
			ncomma++;
		else if (line[i] < '0' && line[i] > '9')
			return (1);
		i++;
	}
	if (ncomma != 2)
		return (1);
	return (0);
}

int	*getrgb(t_mlx *mlx, char *line, int *tab, int nwall)
{
	char	**rgb;
	int		start;

	start = 0;
	while (line[start] != ' ' && line[start] != '\t' && line[start])
		start++;
	if (ft_checkrgb(&line[start]) == 1)
		ft_exitreadfile(mlx, "ERROR: invalid RGB format\n", nwall);
	rgb = ft_split(&line[start], ',');
	tab[0] = ft_atoi(rgb[0]);
	tab[1] = ft_atoi(rgb[1]);
	tab[2] = ft_atoi(rgb[2]);
	ft_free_strarr(rgb);
	start = 0;
	while (start < 3)
	{
		if (tab[start] < 0 || tab[start] > 255)
			ft_exitreadfile(mlx, "ERROR: Invalid RGB color value\n", nwall);
		start++;
	}
	return (tab);
}
