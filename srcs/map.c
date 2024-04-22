/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kro <kro@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:58:55 by hbaduel           #+#    #+#             */
/*   Updated: 2023/12/13 13:12:54 by kro              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_check_cub(t_mlx *mlx, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 4] != '.' || str[i - 3] != 'c'
		|| str[i - 2] != 'u' || str[i - 1] != 'b')
	{
		mlx->data->map = NULL;
		ft_putstr("\nERROR : map is not a .cub file\n");
		ft_exitstart(mlx, 7);
	}
}

int	ft_filelenght(t_mlx *mlx, char *mapfile)
{
	int		fd;
	int		i;
	char	buffer[1];

	i = 0;
	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("ERROR :\n\tMap does not exist.\n");
		ft_freestart(mlx, mlx->start, 7);
		free(mlx->start);
		free(mlx->data);
		free(mlx->player);
		mlx_destroy_display(mlx->mlx);
		free(mlx);
		exit (1);
	}
	while (read(fd, buffer, 1) != 0)
		i++;
	close(fd);
	return (i);
}

char	**ft_readfile(t_mlx *mlx, char *mapfile)
{
	char	*buffer;
	char	**map;
	int		fd;
	int		size;

	ft_check_cub(mlx, mapfile);
	size = ft_filelenght(mlx, mapfile);
	buffer = malloc(sizeof(char *) * (size + 1));
	fd = open(mapfile, O_RDONLY);
	read(fd, buffer, size);
	buffer[size] = '\0';
	close(fd);
	map = ft_split(buffer, '\n');
	free(buffer);
	return (map);
}

char	**ft_cutmap(char **file)
{
	char	**map;
	int		i;
	int		j;

	i = 6;
	while (file[i])
		i++;
	map = malloc(sizeof(char *) * (i - 6 + 1));
	i = 6;
	j = 0;
	while (file[i])
	{
		map[j] = ft_strdup(file[i]);
		i++;
		j++;
	}
	map[j] = NULL;
	ft_free_strarr(file);
	return (map);
}
