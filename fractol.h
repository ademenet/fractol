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
	void			*img;
	char			*img_data;
	int 			bpp;
	int 			sl;
	int 			endian;

}					t_env;

#endif