#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include "libft/ft_printf/include/fpf_printf.h"

# define WIN_WIDTH 700
# define WIN_HEIGHT 500

/*
** This structure is for shared options for every fractals.
*/

typedef struct      s_fal
{
	void			(*ptr)();
	int				max_iter;
	float			zoom_x;
	float			zoom_y;
	float			x1;
	float			y1;
	float			x2;
	float			y2;
	float			c_r;
	float			c_i;
	float			z_r;
	float			z_i;
}                   t_fal;

/*
** This structure store environment settings for mlx purpose.
*/

typedef struct		s_env
{
	char			*im_buf;
	int 			bpp;
	int 			endian;
	int 			sl;
	int				size_x;
	int				size_y;
	void			*mlx;
	void			*win;
	void			*im;
	t_fal			*fal;
}					t_env;

/*
** images.c
*/

void		put_pixel(t_env *env, int x, int y, int color);
void        fractals_compute(t_env *env, t_fal *fal);
int			put_image(t_env *env, t_fal *fal);

/*
** fractals.c
*/

void		set_limits(t_env *env, t_fal *fal);

/*
** mandelbrot.c
*/

void		mandelbrot(int x, int y, t_fal *fal, t_env *env);

/*
** julia.c
*/

void		julia(int x, int y, t_fal *fal, t_env *env);

/*
** burningship.c
*/

void        burningship(int x, int y, t_fal *fal, t_env *env);

/*
** hooks.c
*/

int			events(int keycode, t_env *env);

#endif
