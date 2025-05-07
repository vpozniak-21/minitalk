/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:34:57 by vpozniak          #+#    #+#             */
/*   Updated: 2025/02/06 10:39:28 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_handle_spec(char spcfr, int *len, va_list args);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putnbr_base(unsigned long value, int specifier);
char	*ft_strchr(const char *str, int c);

#endif
