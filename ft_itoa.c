/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:21:02 by lbertran          #+#    #+#             */
/*   Updated: 2020/11/27 16:04:06 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rev_tab(char *tab, int size)
{
	int	i;
	int	swap;

	i = 0;
	while (i < size / 2)
	{
		swap = tab[i];
		tab[i] = tab[size - (i + 1)];
		tab[size - (i + 1)] = swap;
		++i;
	}
	return (tab);
}

int		count_chars(int nbr)
{
	int		count;
	long	nb;

	nb = nbr;
	count = 0;
	if (nb < 0)
	{
		count++;
		nb = -nb;
	}
	if (nb == 0)
		count++;
	while (nb)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa2(long nb, char *str)
{
	int		neg;
	size_t	i;

	neg = 0;
	i = 0;
	if (nb < 0)
	{
		neg = 1;
		nb = -nb;
	}
	while (nb)
	{
		str[i] = nb % 10 + 48;
		nb /= 10;
		i++;
	}
	if (neg)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_rev_tab(str, ft_strlen(str)));
}

char	*ft_itoa(int nbr)
{
	long	nb;
	char	*str;

	nb = nbr;
	if (!(str = malloc(sizeof(char) * (count_chars(nbr) + 1))))
		return (NULL);
	if (nb == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	return (ft_itoa2(nb, str));
}
