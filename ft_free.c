/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:02:48 by aomman            #+#    #+#             */
/*   Updated: 2022/03/25 16:06:01 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free2(t_var var)
{
	var.i = 0;
	while (var.spl[var.i])
	{
		free (var.spl[var.i]);
		var.i++;
	}
	free (var.spl);
}

int	ft_exit_corss(void)
{
	exit (0);
	return (0);
}
