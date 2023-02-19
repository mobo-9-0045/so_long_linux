/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:41:49 by aomman            #+#    #+#             */
/*   Updated: 2022/03/16 17:42:07 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"so_long.h"

void	ft_alocate_player(t_var *var)
{
	var->i = 0;
	while (var->spl[var->i])
	{
		var->j = 0;
		while (var->spl[var->i][var->j])
		{
			if (var->spl[var->i][var->j] == 'P')
				break ;
			var->j++;
		}
		if (var->spl[var->i][var->j] == 'P')
			break ;
		var->i++;
	}
}

void	count_colls(t_var *var)
{
	var->coll = 0;
	var->i = 0;
	while (var->spl[var->i])
	{
		var->j = 0;
		while (var->spl[var->i][var->j])
		{
			if (var->spl[var->i][var->j] == 'C')
				var->coll++;
			var->j++;
		}
		var->i++;
	}
}

int	ft_exit(t_var *var)
{
	count_colls(var);
	if (var->coll != 0)
		return (1);
	write(1, "YOU WIN", 7);
	exit(0);
	return (0);
}

int	ft_check_exit(t_var *var, int c)
{
	if (c == 119 && var->spl[var->i - 1][var->j] == 'E')
		return (ft_exit(var));
	else if (c == 97 && var->spl[var->i][var->j - 1] == 'E')
		return (ft_exit(var));
	else if (c == 115 && var->spl[var->i + 1][var->j] == 'E')
		return (ft_exit(var));
	else if (c == 100 && var->spl[var->i][var->j + 1] == 'E')
		return (ft_exit(var));
	return (0);
}

int	deal(int c, t_var *var)
{
	ft_alocate_player(var);
	if (c == 65307)
	{
		write (1, "Exit\n", 5);
		exit (0);
	}
	if (c == 119 && var->spl[var->i - 1][var->j] != '1')
		ft_forword(var, c);
	if (c == 97 && var->spl[var->i][var->j - 1] != '1')
		ft_left(var, c);
	if (c == 115 && var->spl[var->i + 1][var->j] != '1')
		ft_down(var, c);
	if (c == 100 && var->spl[var->i][var->j + 1] != '1')
		ft_right(var, c);
	return (0);
}
