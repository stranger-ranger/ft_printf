/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llatrice <llatrice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:27:28 by llatrice          #+#    #+#             */
/*   Updated: 2021/12/25 15:06:03 by llatrice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	f_uns(unsigned int u_int)
{
	int	u_1;
	int	sum;

	sum = 0;
	u_1 = u_int / 100000;
	if (u_1)
		ft_itoa(u_1, &sum);
	ft_itoa(u_int % 100000, &sum);
	return (sum);
}

int	ft_string(char *s)
{
	int	i;
	int	sum;

	sum = 0;
	i = 0;
	if (!s)
		return (ft_string("(null)"));
	while (s[i])
	{
		ft_putchar(s[i], &sum);
		i++;
	}
	return (sum);
}

int	ft_pointer(void *s)
{
	int	i;

	i = 0;
	ft_putchar('0', &i);
	ft_putchar('x', &i);
	i = i + ft_hex_pointer((unsigned long int)s);
	return (i);
}

int	ft_format(char f, va_list	ap, int sum)
{
	if (f == 'c')
		ft_putchar(va_arg(ap, int), &sum);
	if (f == 's')
		sum += ft_string(va_arg(ap, char *));
	if (f == 'p')
		sum += ft_pointer(va_arg(ap, void *));
	if (f == 'd' || f == 'i')
		ft_itoa(va_arg(ap, int), &sum);
	if (f == 'u')
		sum += f_uns(va_arg(ap, int));
	if (f == 'x' || f == 'X')
		sum = ft_hex(va_arg(ap, unsigned int), f, sum);
	if (f == '%')
		ft_putchar('%', &sum);
	return (sum);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	ap;
	int		sum;

	sum = 0;
	i = 0;
	va_start (ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			sum = ft_format(s[i], ap, sum);
		}
		else
		{
			write (1, &s[i], 1);
			sum++;
		}
		i++;
	}
	va_end (ap);
	return (sum);
}
