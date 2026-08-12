/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsign_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 18:14:05 by grocca            #+#    #+#             */
/*   Updated: 2026/07/01 18:14:07 by grocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	n_unsgnlen(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_putunsign_fd(unsigned int n, int fd)
{
	char	s[11];
	int		len;

	len = 0;
	if (!n)
		return (write(fd, "0", 1));
	len = n_unsgnlen(n);
	s[len] = '\0';
	while (n)
	{
		s[len - 1] = '0' + n % 10;
		n = n / 10;
		len--;
	}
	return (write(fd, s, ft_strlen(s)));
}
