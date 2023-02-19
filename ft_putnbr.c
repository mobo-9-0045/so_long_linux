/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:50:31 by aomman            #+#    #+#             */
/*   Updated: 2022/03/23 17:52:40 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<stdio.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int	i;

	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	i = n;
	if (i <= 9)
		ft_putchar(i + 48);
	if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
}

char	*ft_strrchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i = i + 1;
	while (i >= 0)
	{
		if (str[i] == (char) c)
			return (str + i);
		i--;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
