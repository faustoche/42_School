/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:53:40 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

int	ft_putdi(int nb);
int	ft_format(va_list lst, char format);
int	ft_putc(char c);
int	ft_printf(const char *format, ...);
int	ft_hexamaj(unsigned long nb);
int	ft_hexamin(unsigned long nb);
int	ft_putx(unsigned int n, char format);
int	ft_putp(void *arg);
int	ft_hexa(unsigned long arg);
int	ft_puts(char *s);
int	ft_putun(unsigned int nb);

#endif