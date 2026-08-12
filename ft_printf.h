/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorregr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 19:00:14 by dtorregr          #+#    #+#             */
/*   Updated: 2026/06/17 16:25:00 by dtorregr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int		ft_printf(int fd, const char *format, ...);
int		ft_putchar_fd(char c, int fd);
char	*ft_hexstr(char *s, unsigned long n);
int		ft_putnbr_fd(int n, int fd);
int		ft_putunsign_fd(unsigned int n, int fd);
int		ft_putpoint_fd(void *p, char *s, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_toupper(char *s);
size_t	ft_strlen(const char *s);

#endif
