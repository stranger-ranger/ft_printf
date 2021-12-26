/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llatrice <llatrice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:20:52 by llatrice          #+#    #+#             */
/*   Updated: 2021/12/25 14:54:22 by llatrice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_hex_pointer(unsigned long int n);
int		ft_hex(unsigned int i_c, char f, int sum);
int		ft_singlechar(char c);

void	ft_itoa(int n, int *sum);
void	ft_putchar(char c, int *sum);
void	ft_hex_x(unsigned long int n, int *i);
void	ft_hex_xx(unsigned long int n, int *i);

#endif
