/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:52:45 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdi(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		len = 11;
	}
	else if (nb < 0)
	{
		len += ft_putc('-');
		len += ft_putdi(-nb);
	}
	else if (nb >= 10)
	{
		len += ft_putdi(nb / 10);
		len += ft_putdi(nb % 10);
	}
	else
		len += ft_putc(nb % 10 + '0');
	return (len);
}
