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

/*
** Flag which fractal to display in env.arg array.
*/

char		*parser(char **argv, char *arg_parse)
{
	if (ft_strcmp("mandelbrot", argv[1]) == 0)
		arg_parse[0] = 1;
	else if (ft_strcmp("julia", argv[1]) == 0)
		arg_parse[1] = 1;
	else if (ft_strcmp("burningship", argv[1]) == 0)
		arg_parse[2] = 1;
	else
		display_usage();
	return arg_parse;
}

int		main(int argc, char **argv)
{
	t_env	env;

	// initialize arg array with 0
	ft_bzero(env.arg, 3);
	// parse command lines
	if (argc < 2 || argc > 3)
		display_usage();
	else
		parser(argv, env.arg);
	// initialize mlx server
	env.mlx = mlx_init();
	// set a window
	env.win = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, "Fract'ol by ademenet");
	// create, process and display image
	put_image(&env);
	mlx_loop(env.mlx);
	return (0);
}
