void	ft_error(char *s)
{
	if (s == NULL)
		perror("error");
	else
	{
		ft_putstr("error: ");
		ft_putstr(s);
		ft_putstr(".\n");
	}
	exit(-1);
}

int		main(int ac, char **av)
{
	t_env	env;

	if (ac == 2)
	{
		env.mlx = mlx_init();
		env.win = mlx_new_window(env.mlx, WIN_X, WIN_Y, "Fractol");
		env.im = mlx_new_image(env.mlx, WIN_X, WIN_Y);
		env.imc = mlx_get_data_addr(env.img, &env.bpp, &env.sl, &env.endian);
	}
	else
		ft_error("too much arguments or not enough");
	return (0);
}