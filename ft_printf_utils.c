/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llatrice <llatrice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:03:09 by llatrice          #+#    #+#             */
/*   Updated: 2021/12/25 14:49:54 by llatrice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *sum)
{
	write (1, &c, 1);
	(*sum)++;
}

int	ft_singlechar(char c)
{
	write (1, &c, 1);
	return (1);
}

static int	ft_ilen(int num)
{
	int	len;

	len = 0;
	if (num < 0)
		len++;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static void	ft_itoa_recurse(int num, int len, int *sum)
{
	int	c;

	if (num > -10)
	{
		c = '0' - num;
		write (1, &c, 1);
		(*sum)++;
	}
	else
	{
		ft_itoa_recurse(num / 10, len - 1, sum);
		c = '0' - num % 10;
		write (1, &c, 1);
		(*sum)++;
	}
}

void	ft_itoa(int n, int *sum)
{
	int	kol;
	int	s;

	s = 0;
	kol = ft_ilen(n);
	if (n == 0)
	{
		ft_putchar('0', &s);
		(*sum) += s;
		return ;
	}
	if (n > 0)
		n = -n;
	else
		ft_putchar('-', &s);
	ft_itoa_recurse(n, kol - 1, &s);
	(*sum) += s;
}
