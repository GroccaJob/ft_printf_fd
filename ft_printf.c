/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 18:12:09 by grocca            #+#    #+#             */
/*   Updated: 2026/07/01 18:12:13 by grocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_function(int fd, const char *format, va_list ap)
{
	int		ret;
	char	s[17];

	format++;
	ret = -1;
	if (*format == '%')
		ret = ft_putchar_fd('%', fd);
	else if (*format == 'c')
		ret = ft_putchar_fd((char)va_arg(ap, int), fd);
	else if (*format == 'd' || *format == 'i')
		ret = ft_putnbr_fd(va_arg(ap, int), fd);
	else if (*format == 's')
		ret = ft_putstr_fd(va_arg(ap, char *), fd);
	else if (*format == 'u')
		ret = ft_putunsign_fd(va_arg(ap, unsigned int), fd);
	else if (*format == 'p')
		ret = ft_putpoint_fd(va_arg(ap, void *), s, fd);
	else if (*format == 'x' || *format == 'X')
	{
		ft_hexstr(s, va_arg(ap, unsigned int));
		if (*format == 'X')
			ft_toupper(s);
		ret = ft_putstr_fd(s, fd);
	}
	return (ret);
}

int	ft_printf(int fd, const char *format, ...)
{
	int		ret;
	int		count;
	va_list	ap;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format != '%')
			ret = write(fd, format, 1);
		else
		{
			ret = ft_function(fd, format, ap);
			format++;
		}
		if (ret == -1)
		{
			va_end(ap);
			return (-1);
		}
		count += ret;
		format++;
	}
	va_end(ap);
	return (count);
}
