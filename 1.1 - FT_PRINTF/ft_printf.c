/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:48:41 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list lst, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += (char)ft_putc(va_arg(lst, int));
	else if (format == 's')
		len += ft_puts(va_arg(lst, char *));
	else if (format == 'p')
		len += ft_putp(va_arg(lst, void *));
	else if (format == 'd' || format == 'i')
		len += ft_putdi(va_arg(lst, int));
	else if (format == 'u')
		len += ft_putun(va_arg(lst, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_putx(va_arg(lst, int), format);
	else if (format == '%')
			len += ft_putc('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	lst;

	i = 0;
	len = 0;
	if (!format)
		return (-1);
	va_start(lst, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_format(lst, format[i]);
		}
		else
			len += ft_putc(format[i]);
		i++;
	}
	va_end(lst);
	return (len);
}
/*
int	main(void)
{
	char	*test = 0;
	
	ft_printf("%d\n", ft_printf(0));
	printf("%d\n", printf(0));
	ft_printf("%c\n", 'F');
	printf("%c\n", 'F');
	ft_printf("%c", '\n');
	ft_printf("%s\n", "Faustoche");
	printf("%s\n", "Faustoche");
	ft_printf("%c", '\n');
	ft_printf("%s\n", "");
	printf("%s\n", "");
	ft_printf("%c", '\n');
	ft_printf("%p\n", &test);
	printf("%p\n", &test);
	ft_printf("%c", '\n');
	ft_printf("%p\n", test);
	printf("%p\n", test);
	ft_printf("%c", '\n');
	ft_printf("%d\n", 42);
	printf("%d\n", 42);
	ft_printf("%c", '\n');
	ft_printf("%i\n", 5456);
	printf("%i\n", 5456);
	ft_printf("%c", '\n');
	ft_printf("%u\n", 42);
	printf("%u\n", 42);
	ft_printf("%c", '\n');
	ft_printf("%x\n", 985);
	printf("%x\n", 985);
	ft_printf("%c", '\n');
	ft_printf("%X\n", 5);
	printf("%X\n", 5);
	ft_printf("%c", '\n');
	ft_printf("%%\n");
	printf("%%\n");
	ft_printf("%c", '\n');
	ft_printf("%%\n");
	printf("%%\n");
}*/