/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysarrar <aysarrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:18:07 by aysarrar          #+#    #+#             */
/*   Updated: 2022/01/06 14:49:40 by aysarrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_count_number(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*number;
	long	nbr;

	nbr = n;
	size = ft_count_number(nbr) + 1;
	number = malloc(size);
	if (!number)
		return (NULL);
	if (nbr < 0)
	{
		number[0] = '-';
		nbr = -nbr;
	}
	size--;
	number[size] = '\0';
	if (nbr == 0)
		number[0] = '0';
	while (nbr != 0)
	{
		number[--size] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (number);
}
