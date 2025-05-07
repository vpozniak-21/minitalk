/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpozniak <vpozniak@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:34:14 by vpozniak          #+#    #+#             */
/*   Updated: 2025/02/07 20:02:39 by vpozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle_chr(int *len, va_list args);
static void	ft_handle_str(int *len, va_list args);
static void	ft_handle_pntr(int *len, va_list args);
static void	ft_handle_nbr(char specifier, int *len, va_list args);

void	ft_handle_spec(char spcfr, int *len, va_list args)
{
	if (spcfr == 'c')
		ft_handle_chr(len, args);
	else if (spcfr == 's')
		ft_handle_str(len, args);
	else if (spcfr == 'p')
		ft_handle_pntr(len, args);
	else if (ft_strchr("uxXdi", spcfr))
		ft_handle_nbr(spcfr, len, args);
	else if (spcfr == '%')
		*len += write(1, "%", 1);
}

static void	ft_handle_chr(int *len, va_list args)
{
	char	c;

	c = va_arg(args, int);
	*len += write(1, &c, 1);
}

static void	ft_handle_str(int *len, va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
		*len += write(1, "(null)", 6);
	else
		*len += ft_putstr(str);
}

static void	ft_handle_pntr(int *len, va_list args)
{
	unsigned long	ptr;

	ptr = va_arg(args, unsigned long);
	if (!ptr)
		*len += ft_putstr("(nil)");
	else
		*len += ft_putstr("0x") + ft_putnbr_base(ptr, 'p');
}

static void	ft_handle_nbr(char specifier, int *len, va_list args)
{
	if (specifier == 'd' || specifier == 'i')
		*len += ft_putnbr(va_arg(args, int));
	else if (ft_strchr("uxX", specifier))
		*len += ft_putnbr_base(va_arg(args, unsigned int), specifier);
}
