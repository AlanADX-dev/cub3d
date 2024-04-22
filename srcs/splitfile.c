/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaduel <hbaduel@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:56:04 by hbaduel           #+#    #+#             */
/*   Updated: 2023/12/13 12:10:28 by hbaduel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_texture	*ft_init_texture(t_mlx *mlx, char *name)
{
	t_texture	*img;
	int			x;
	int			y;

	img = malloc(sizeof(t_texture));
	img->size_line = 1024;
	img->bpp = 32;
	img->endian = 0;
	img->img_ptr = mlx_xpm_file_to_image(mlx->mlx, name, &x, &y);
	if (!img->img_ptr)
	{
		free(img);
		return (NULL);
	}
	img->img_data = \
	mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_line, &img->endian);
	return (img);
}

char	*ft_namefile(t_mlx *mlx, char *line, int code)
{
	char	*file;
	int		start;
	int		end;
	int		i;

	start = 0;
	while ((line[start] == ' ' || line[start] == '\t') && line[start])
		start++;
	if (!line[start])
		ft_exitreadfile(mlx, "ERROR : No file for a wall\n", code);
	end = start;
	while (line[end] != ' ' && line[end] != '\t' && line[end])
		end++;
	file = malloc(sizeof(char) * (end - start + 1));
	i = 0;
	while (start < end)
	{
		file[i] = line[start];
		i++;
		start++;
	}
	file[i] = '\0';
	return (file);
}

t_texture	*ft_openimg(t_mlx *mlx, char *line, int *j)
{
	char		*file;
	t_texture	*img;

	file = ft_namefile(mlx, line, *j);
	img = ft_init_texture(mlx, file);
	if (!img)
	{
		ft_putstr("ERROR : ");
		ft_putstr(file);
		free(file);
		ft_exitreadfile(mlx, " not found\n", *j);
	}
	free(file);
	*j += 1;
	return (img);
}

void	ft_whichidentifier(t_mlx *mlx, char *file, int *j)
{
	if (ft_strncmp("NO", file, 2) == 0)
		mlx->data->north = ft_openimg(mlx, &file[2], j);
	else if (ft_strncmp("SO", file, 2) == 0)
		mlx->data->south = ft_openimg(mlx, &file[2], j);
	else if (ft_strncmp("WE", file, 2) == 0)
		mlx->data->west = ft_openimg(mlx, &file[2], j);
	else if (ft_strncmp("EA", file, 2) == 0)
		mlx->data->east = ft_openimg(mlx, &file[2], j);
	else if (ft_strncmp("F", file, 1) == 0)
		getrgb(mlx, &file[1], &mlx->data->floor[0], *j);
	else if (ft_strncmp("C", file, 1) == 0)
		getrgb(mlx, &file[1], &mlx->data->ceiling[0], *j);
}

void	ft_splitfile(t_mlx *mlx, char **file)
{
	int	i;
	int	j;

	mlx->data->map = file;
	if (ft_strarrlen(file) < 6)
		ft_exitreadfile(mlx, "ERROR: Missing information\n", 0);
	ft_checkidentifier(mlx, file);
	i = 0;
	j = 0;
	while (i < 6)
	{
		ft_whichidentifier(mlx, file[i], &j);
		i++;
	}
	mlx->data->map = ft_cutmap(file);
	ft_checkcontent(mlx, mlx->data->map);
	ft_checklignclose(mlx, mlx->data->map);
	ft_checkcolumnclose(mlx, mlx->data->map);
}
