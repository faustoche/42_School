/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:53:48 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putp(void *arg)
{
	int				count;
	unsigned long	arg2;

	count = 0;
	arg2 = (unsigned long)arg;
	if (arg == 0)
		return (write(1, "(nil)", 5));
	count += ft_puts("0x");
	count += ft_hexa(arg2);
	return (count);
}

int	ft_hexa(unsigned long arg)
{
	int		count;
	char	*hexa;

	count = 0;
	hexa = "0123456789abcdef";
	if (arg > 15)
	{
		count += ft_hexa(arg / 16);
		count += ft_hexa(arg % 16);
	}
	else
		count += ft_putc(hexa[arg]);
	return (count);
}
