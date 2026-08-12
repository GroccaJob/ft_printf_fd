/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 16:01:48 by grocca            #+#    #+#             */
/*   Updated: 2026/06/06 17:27:32 by grocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	n_len(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_fd(int n, int fd)
{
	char	p[12];
	size_t	len;

	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	else if (n == 0)
		return (write(fd, "0", 1));
	else
	{
		len = n_len(n);
		p[len] = '\0';
		if (n < 0)
		{
			p[0] = '-';
			n = -n;
		}
		while (n)
		{
			p[len - 1] = '0' + n % 10;
			n = n / 10;
			len--;
		}
		return (write(fd, p, ft_strlen(p)));
	}
}
