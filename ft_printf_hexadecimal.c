/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexadecimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llatrice <llatrice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:50:50 by llatrice          #+#    #+#             */
/*   Updated: 2021/12/25 14:52:10 by llatrice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex_x(unsigned long int n, int *i)
{
	char	*str;
	int		hex;

	hex = 0;
	str = "0123456789abcdef";
	if (n < 0)
	{
		n = -n;
		write (1, "-", 1);
		(*i)++;
	}
	if (!n)
		return ;
	else
	{
		hex = n % 16;
		ft_hex_x(n / 16, i);
	}
	write (1, &str[hex], 1);
	(*i)++;
}

void	ft_hex_xx(unsigned long int n, int *i)
{
	char	*str;
	int		hex;

	hex = 0;
	str = "0123456789ABCDEF";
	if (n < 0)
	{
		n = -n;
		write (1, "-", 1);
		(*i)++;
	}
	if (!n)
		return ;
	else
	{
		hex = n % 16;
		ft_hex_xx(n / 16, i);
	}
	write (1, &str[hex], 1);
	(*i)++;
}

int	ft_hex_pointer(unsigned long int n)
{
	char	*str;
	int		i;

	str = "0123456789abcdef";
	if (n < 16)
		return (ft_singlechar(str[n]));
	else
	{
		i = ft_hex_pointer(n / 16);
		ft_hex_pointer(n % 16);
	}
	return (i + 1);
}

int	ft_hex(unsigned int i_c, char f, int sum)
{
	if (i_c)
	{
		if (f == 'x')
			ft_hex_x(i_c, &sum);
		else
			ft_hex_xx(i_c, &sum);
	}
	else
		ft_putchar('0', &sum);
	return (sum);
}
