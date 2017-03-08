#include "fractol.h"

// CHECK: errors

/*
** Error handling and displaying
*/

void		display_usage(void)
{
	ft_printf("Usage: ./fractol <fractal>\n");
	ft_printf("Fractals: mandelbrot, julia, third\n");
	exit(EXIT_FAILURE);
}

void		mandelbrot_initalization(t_fal *fal)
{
	fal->ptr = &mandelbrot;
	fal->x1 = -2.1;
	fal->x2 = 0.6;
	fal->y1 = -1.2;
	fal->y2 = 1.2;
	fal->max_iter = 100;
	fal->zoom_x = WIN_WIDTH / (fal->x2 - fal->x1);
	fal->zoom_y = WIN_HEIGHT / (fal->y2 - fal->y1);
}

void		julia_initalization(t_fal *fal)
{
	fal->ptr = &julia;
	fal->x1 = -1;
	fal->x2 = 1;
	fal->y1 = -1.2;
	fal->y2 = 1.2;
	fal->max_iter = 100;
	fal->c_r = 0.285;
	fal->c_i = 0.01;
	fal->zoom_x = WIN_WIDTH / (fal->x2 - fal->x1);
	fal->zoom_y = WIN_HEIGHT / (fal->y2 - fal->y1);
}

void		burningship_initalization(t_fal *fal)
{
	fal->ptr = &burningship;
	fal->x1 = -1;
	fal->x2 = 1;
	fal->y1 = -1.2;
	fal->y2 = 1.2;
	fal->max_iter = 100;
	fal->zoom_x = WIN_WIDTH / (fal->x2 - fal->x1);
	fal->zoom_y = WIN_HEIGHT / (fal->y2 - fal->y1);
}

/*
** Flag which fractal to display in env.arg array.
*/

int			parser(char **argv, t_fal *fal)
{
	if (ft_strcmp("mandelbrot", argv[1]) == 0)
		mandelbrot_initalization(fal);
	else if (ft_strcmp("julia", argv[1]) == 0)
		julia_initalization(fal);
	else if (ft_strcmp("burningship", argv[1]) == 0)
		burningship_initalization(fal);
	else
		display_usage();
	return (1);
}

int		main(int argc, char **argv)
{
	t_env	env;
	t_fal	fal;

	// parse command lines
	env.fal = &fal;
	if (argc < 2 || argc > 3)
		display_usage();
	else
		parser(argv, &fal);
	// initialize minilibx variables
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, "Fract'ol by ademenet");
	// create, process and display image
	put_image(&env, &fal);
	mlx_hook(env.win, 2, 1, &events, &env);
	mlx_hook(env.win, 6, 1, &params, &env);
	mlx_loop(env.mlx);
	return (0);
}
