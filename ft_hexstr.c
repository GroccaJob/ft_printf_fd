/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 18:10:59 by grocca            #+#    #+#             */
/*   Updated: 2026/07/01 18:11:03 by grocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	n_lenbase(unsigned long n, int base)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n = n / base;
		len++;
	}
	return (len);
}

char	*ft_hexstr(char *s, unsigned long n)
{
	int	len;

	len = n_lenbase(n, 16);
	s[len] = '\0';
	if (!n)
		s[0] = '0';
	while (n)
	{
		if (n % 16 < 10)
			s[len - 1] = '0' + n % 16;
		if (n % 16 >= 10)
			s[len - 1] = 'a' + n % 16 - 10;
		n = n / 16;
		len--;
	}
	return (s);
}
