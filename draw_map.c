/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:46:21 by aomman            #+#    #+#             */
/*   Updated: 2022/03/25 19:14:12 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"so_long.h"

void	check_comp(t_var var)
{
	if (var.exit <= 0)
	{
		write (1, "Error : no exit in map\n", 23);
		exit (1);
	}
	if (var.coll <= 0)
	{
		write (1, "Error : collectible not exist\n", 30);
		exit (1);
	}
	if (var.player <= 0 || var.player > 1)
	{
		write (1, "should be only one plyaer in map\n", 33);
		exit (1);
	}
}

void	check_map_comp(t_var var)
{
	var.i = 0;
	var.player = 0;
	var.coll = 0;
	var.exit = 0;
	while (var.spl[var.i])
	{
		var.j = 0;
		while (var.spl[var.i][var.j])
		{
			if (var.spl[var.i][var.j] == 'P')
				var.player++;
			if (var.spl[var.i][var.j] == 'C')
				var.coll++;
			if (var.spl[var.i][var.j] == 'E')
				var.exit++;
			var.j++;
		}
		var.i++;
	}
	check_comp(var);
}

void	start_draw(t_var *v)
{
	if (v->spl[v->i][v->j] == '1')
	{
		v->i_w = mlx_xpm_file_to_image(v->mlx, "img/wall.xpm", &v->w, &v->h);
		mlx_put_image_to_window(v->mlx, v->win, v->i_w, v->j * 50, v->i * 50);
	}
	else if (v->spl[v->i][v->j] == '0')
	{
		v->i_w = mlx_xpm_file_to_image(v->mlx, "img/sky.xpm", &v->w, &v->h);
		mlx_put_image_to_window(v->mlx, v->win, v->i_w, v->j * 50, v->i * 50);
	}
	else if (v->spl[v->i][v->j] == 'P')
	{
		v->i_w = mlx_xpm_file_to_image(v->mlx, "img/p.xpm", &v->w, &v->h);
		mlx_put_image_to_window(v->mlx, v->win, v->i_w, v->j * 50, v->i * 50);
	}
	else if (v->spl[v->i][v->j] == 'E')
	{
		v->i_w = mlx_xpm_file_to_image(v->mlx, "img/door.xpm", &v->w, &v->h);
		mlx_put_image_to_window(v->mlx, v->win, v->i_w, v->j * 50, v->i * 50);
	}
	else if (v->spl[v->i][v->j] == 'C')
	{
		v->i_w = mlx_xpm_file_to_image(v->mlx, "img/ball.xpm", &v->w, &v->h);
		mlx_put_image_to_window(v->mlx, v->win, v->i_w, v->j * 50, v->i * 50);
	}
}

void	draw_map(t_var *v)
{
	v->i = 0;
	while (v->spl[v->i])
	{
		v->j = 0;
		while (v->spl[v->i][v->j])
		{
			start_draw(v);
			v->j++;
		}
		v->i++;
	}
}

int	main(int argc, char **argv)
{
	t_var	var;

	var.n_moves = 1;
	var.fd = open(argv[1], O_RDONLY, 0777);
	check_ber(argc, argv);
	var.gcl = get_next_line(var.fd);
	check_map_file(var);
	var.spl = ft_split(var.gcl, '\n');
	free (var.gcl);
	var.i = 0;
	var.j = 0;
	while (var.spl[var.i])
	{
		while (var.spl[var.i][var.j] != '\0')
			var.j++;
		var.i++;
	}
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, var.j * 50, var.i * 50, "so_long");
	check_map_comp(var);
	draw_map(&var);
	mlx_key_hook (var.win, deal, &var);
	mlx_hook (var.win, 17, 0, ft_exit_corss, &var);
	mlx_loop(var.mlx);
}
