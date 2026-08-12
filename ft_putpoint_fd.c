/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 18:13:17 by grocca            #+#    #+#             */
/*   Updated: 2026/07/01 18:13:30 by grocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpoint_fd(void *p, char *s, int fd)
{
	int	len;

	len = 0;
	if (!p)
		return (write(fd, "(nil)", 5));
	ft_hexstr(s, (unsigned long)p);
	len = ft_strlen(s);
	if (write(fd, "0x", 2) == -1 || write(fd, s, len) == -1)
		return (-1);
	return (2 + len);
}
