#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft/libft.h"

# define WIN_X 800
# define WIN_Y 600

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

#endif