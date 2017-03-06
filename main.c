#include "fractol.h"

/*
** Error handling and displaying
*/

void		display_usage(void)
{
	ft_printf("| Please use Fract'ol like this:\n");
	ft_printf("| \t./fractol <fractal> [options]\n");
	ft_printf("| Fractals: mandelbrot, julia, third\n");
}

char		*parser(char **argv, char *arg_parse)
{
	if (ft_strcmp("mandelbrot", argv[1]) == 0)
		arg_parse[0] = 1;
	else if (ft_strcmp("julia", argv[1]) == 0)
		arg_parse[1] = 1;
	else if (ft_strcmp("third", argv[1]) == 0)
		arg_parse[2] = 1;
	else
		display_usage();
	return arg_parse;
}

// void	ft_error(char *s)
// {
// 	if (s == NULL)
// 		perror("error");
// 	else
// 	{
// 		ft_putstr("error: ");
// 		ft_putstr(s);
// 		ft_putstr(".\n");
// 	}
// 	exit(-1);
// }



int		main(int argc, char **argv)
{
	t_env	env;

	// TODO: parser!!!
	if (argc < 2)
		display_usage();
	else
		parser(argv, env.arg);
	// TODO: error handling
	// BONUS: cuda
	// if (ac == 2)
	// {
	ft_printf("%d", env.arg[0]);
	env.mlx = mlx_init(); // initialize mlx server
	env.win = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, "Fract'ol"); // set a window
    // Instead of followings functions, we'll use put_image now:
	// env.im = mlx_new_image(env.mlx, WIN_WIDTH, WIN_HEIGHT); // create a new image in memory
	// env.im_buf = mlx_get_data_addr(env.im, &env.bpp, &env.sl, &env.endian);
	put_image(&env); // create, process and display image
	mlx_loop(env.mlx);
	// }
	// else
	// 	ft_error("too much arguments or not enough");
	return (0);
}
