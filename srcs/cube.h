/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kro <kro@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:51:18 by hbaduel           #+#    #+#             */
/*   Updated: 2023/12/13 13:08:58 by kro              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../includes/mlx/mlx.h"
# include "../includes/mlx/mlx_int.h"
# include "../includes/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <math.h>
# include <stdint.h>

typedef struct s_texture
{
	char	*img_data;
	int		bpp;
	int		size_line;
	int		endian;
	void	*img_ptr;
	int		hp;
	int		wall_pos;
}			t_texture;

typedef struct s_ray
{
	double	wx;
	double	wy;
	double	dist;
	char	wall;
}			t_ray;

typedef struct s_start
{
	int		frame;
	int		minimap;
	int		start;
	int		crosshair;
	int		settings;
	void	*bg1;
	void	*bg2;
	void	*bg3;
	void	*set11;
	void	*set01;
	void	*set10;
	void	*set00;
}			t_start;

typedef struct s_data
{
	char		**map;
	t_texture	*north;
	t_texture	*south;
	t_texture	*west;
	t_texture	*east;
	int			ceiling[3];
	int			floor[3];
}			t_data;

typedef struct s_player
{
	double	posx;
	double	posy;
	double	angle;
}			t_player;

typedef struct s_mlx
{
	t_data		*data;
	t_player	*player;
	t_ray		*ray;
	t_start		*start;
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
	int			bpp;
	int			size_line;
	int			endian;
}			t_mlx;

int		ft_exitgame(t_mlx *mlx);
int		handle_keypress(int keysym, t_mlx *mlx);
int		create_trgb(unsigned int t, unsigned int r, \
		unsigned int g, unsigned int b);
int		ft_strarrlen(char **strarr);
int		render(t_mlx *mlx);
int		ft_startingscreen(t_mlx *mlx);
int		start_keypress(int keysym, t_mlx *mlx);
int		start_mouse(int mouse, int x, int y, t_mlx *mlx);
int		ft_movemouse(int x, int y, t_mlx *mlx);
int		*getrgb(t_mlx *mlx, char *line, int *tab, int nwall);
int		ft_movecheck(char **map, double X, double Y);

double	ft_height_projected(t_mlx *mlx);
double	ft_top_wall_position(int *height_projected);
double	ft_correctdist(double dist, double dir, double ray);
double	ft_searchnewpoint(double pos, double diff);

char	**ft_readfile(t_mlx *mlx, char *mapfile);
char	**ft_cutmap(char **file);

void	ft_minimap(t_mlx *mlx, int ip, int jp);
void	ft_exitstart(t_mlx *mlx, int code);
void	ft_free_strarr(char **strarr);
void	ft_exitreadfile(t_mlx *mlx, char *str, int code);
void	ft_freewall(t_mlx *mlx, t_data *data, int code, char **map);
void	ft_freestart(t_mlx *mlx, t_start *start, int code);
void	ft_castfov(t_mlx *mlx);
void	draw_column(t_mlx *mlx, int ray_nb);
void	mlx_pix_put(t_mlx *mlx, int x, int y, int color);
void	ft_set_structs(t_mlx *mlx, char *filename);
void	ft_readmap(t_mlx *mlx, char **map);
void	ft_setrayinf(t_ray *ray, t_player *p, int x, int y);
void	ft_drawsquare4(t_mlx *mlx, int x, int y, int color);
void	ft_drawsquare16(t_mlx *mlx, int x, int y, int color);
void	ft_splitfile(t_mlx *mlx, char **file);
void	ft_checkcontent(t_mlx *mlx, char **map);
void	ft_checkcolumnclose(t_mlx	*mlx, char **map);
void	ft_checklignclose(t_mlx	*mlx, char **map);
void	ft_checkidentifier(t_mlx *mlx, char **map);
void	ft_checktabid(t_mlx *mlx, int *id);

t_ray	*ft_searchwall(t_player *player, double angle, char **map);

# define XPM_SIZE 256
# define HEIGHT 800
# define WIDTH 1280
# define PI 3.14159265358979323846
# define MOVESIZE 8
# define ANGLEMOVESIZE 0.046875
# define FOV 60
# define ANGLEMOVE 2
# define SPEEDMOUSE 0.05

#endif
