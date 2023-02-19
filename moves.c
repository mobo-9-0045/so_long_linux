/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:03:43 by aomman            #+#    #+#             */
/*   Updated: 2022/03/22 23:03:44 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"so_long.h"

int	ft_forword(t_var *var, int c)
{
	if (ft_check_exit(var, c))
		return (0);
	ft_putnbr(var->n_moves++);
	ft_putchar('\n');
	var->spl[var->i - 1][var->j] = 'P';
	var->spl[var->i][var->j] = '0';
	// mlx_clear_window(var->mlx, var->win);
	mlx_destroy_image(var->mlx, var->i_w);
	draw_map(var);
	return (0);
}

int	ft_left(t_var *var, int c)
{
	if (ft_check_exit(var, c))
		return (0);
	ft_putnbr(var->n_moves++);
	ft_putchar('\n');
	var->spl[var->i][var->j - 1] = 'P';
	var->spl[var->i][var->j] = '0';
	// mlx_clear_window(var->mlx, var->win);
	mlx_destroy_image(var->mlx, var->i_w);
	draw_map(var);
	return (0);
}

int	ft_right(t_var *var, int c)
{
	if (ft_check_exit(var, c))
		return (0);
	ft_putnbr(var->n_moves++);
	ft_putchar('\n');
	var->spl[var->i][var->j + 1] = 'P';
	var->spl[var->i][var->j] = '0';
	// mlx_clear_window(var->mlx, var->win);
	mlx_destroy_image(var->mlx, var->i_w);
	draw_map(var);
	return (0);
}

int	ft_down(t_var *var, int c)
{
	if (ft_check_exit(var, c))
		return (0);
	ft_putnbr(var->n_moves++);
	ft_putchar('\n');
	var->spl[var->i + 1][var->j] = 'P';
	var->spl[var->i][var->j] = '0';
	mlx_destroy_image(var->mlx, var->i_w);
	draw_map(var);
	return (0);
}
