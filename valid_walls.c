/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:18:26 by aomman            #+#    #+#             */
/*   Updated: 2022/03/15 12:01:59 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_file(t_var var)
{
	if (!var.gcl)
	{
		write (1, "Error : NO MAP\n", 8);
		exit (1);
	}
	var.i = 0;
	while (var.gcl[var.i])
	{
		if ((var.gcl[var.i] == '\n' && var.gcl[var.i + 1] == '\n')
			|| var.gcl[0] == '\n')
		{
			write (1, "Error : found new line\n", 23);
			exit (1);
		}
		var.i++;
	}
	if (var.gcl[var.i - 1] == '\n')
	{
		write (1, "Error : found new line\n", 23);
		exit (1);
	}
	var.spl = ft_split(var.gcl, '\n');
	valid_walls(var);
}

void	valid_walls(t_var var)
{
	var.j = 0;
	while (var.spl[0][var.j])
	{
		if (var.spl[0][var.j] != '1')
		{
			write (1, "Error : up walls not valid in map\n", 34);
			exit (1);
		}
		var.j++;
	}
	var.i = 0;
	while (var.spl[var.i])
		var.i++;
	var.j = 0;
	while (var.spl[var.i - 1][var.j])
	{
		if (var.spl[var.i - 1][var.j] != '1')
		{
			write (1, "Error : down walls not valid in map\n", 36);
			exit (1);
		}
		var.j++;
	}
	valid_len(var);
}

void	valid_len(t_var var)
{
	int		len;

	var.i = 0;
	len = ft_strlen(var.spl[var.i]);
	while (var.spl[var.i])
	{
		var.j = 0;
		while (var.spl[var.i][var.j])
			var.j++;
		if (len != var.j)
		{
			write (1, "Error : invalid lenght map\n", 27);
			exit (1);
		}
		var.i++;
	}
	check_sides(var);
}

void	check_sides(t_var var)
{
	var.i = 0;
	while (var.spl[var.i])
	{
		var.j = 0;
		while (var.spl[var.i][var.j])
			var.j++;
		if (var.spl[var.i][var.j - 1] != '1')
		{
			write (1, "Error : invalid Right walls in map\n", 35);
			exit (1);
		}
		if (var.spl[var.i][0] != '1')
		{
			write (1, "Error : invalid left walls in map\n", 34);
			exit (1);
		}
		var.i++;
	}
	check_full_comp(var);
}

void	check_full_comp(t_var var)
{
	var.i = 0;
	while (var.spl[var.i])
	{
		var.j = 0;
		while (var.spl[var.i][var.j] != '\0')
		{
			if (var.spl[var.i][var.j] != '1' && var.spl[var.i][var.j] != '0'
				&& var.spl[var.i][var.j] != 'P' && var.spl[var.i][var.j] != 'E'
				&& var.spl[var.i][var.j] != 'C')
			{
				write (1, "Error : Valid elements is : 1 0 P E C\n", 38);
				exit (1);
			}
			var.j++;
		}
		var.i++;
	}
	ft_free2 (var);
}
