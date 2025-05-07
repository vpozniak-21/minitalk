/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:34:46 by vpozniak          #+#    #+#             */
/*   Updated: 2025/02/07 20:23:28 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_putnbr_base(unsigned long arg, int specifier)
{
	char	*base;
	int		base_len;
	int		len;

	base = NULL;
	if (specifier == 'u')
		base = "0123456789";
	else if (specifier == 'x' || specifier == 'p')
		base = "0123456789abcdef";
	else if (specifier == 'X')
		base = "0123456789ABCDEF";
	base_len = 0;
	len = 0;
	while (base[base_len])
		base_len++;
	if (arg >= (unsigned long)base_len)
		len += ft_putnbr_base(arg / base_len, specifier);
	write(1, &base[arg % base_len], 1);
	return (len + 1);
}

int	ft_putnbr(int n)
{
	int		len;
	char	digit;

	len = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		len += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		len += ft_putnbr(n / 10);
	digit = (n % 10) + '0';
	len += write(1, &digit, 1);
	return (len);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
		{
			return ((char *)str);
		}
		str++;
	}
	if (c == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}
