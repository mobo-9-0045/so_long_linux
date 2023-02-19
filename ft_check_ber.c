/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:16:05 by aomman            #+#    #+#             */
/*   Updated: 2022/03/23 19:16:23 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	check_ber(int argc, char **argv)
{
	char	*check;

	if (argc != 2)
	{
		write (1, "Error : ./so_long + map name!!\n", 31);
		exit (1);
	}
	check = ft_strrchr(argv[1], '.');
	if (check == NULL || ft_strcmp(check, ".ber"))
	{
		write (1, "Error : map should ne .ber extention\n", 37);
		exit (1);
	}
}
