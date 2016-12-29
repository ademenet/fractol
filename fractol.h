#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define WIN_WIDTH 270
# define WIN_HEIGHT 240

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*im;
	char			*im_buf;
	int 			bpp;
	int 			endian;

	int 			sl;

	int				size_x;
	int				size_y;
}					t_env;

/*
** images.c
*/

void		put_pixel(t_env *env, int x, int y, int color);
int			put_image(t_env *env);

/*
** fractals.c
*/

void		fractals_compute(t_env *env);

/*
** mandelbrot.c
*/

void		mandelbrot(int x, int y, t_mdl *mdl, t_env *env);

#endif
