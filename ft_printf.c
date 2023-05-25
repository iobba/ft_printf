/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:44:42 by iobba             #+#    #+#             */
/*   Updated: 2022/11/01 17:22:06 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	formattt(va_list ptr, char c)
{
	int	sum;

	sum = 0;
	if (c == 'c')
		sum += ft_putchar((char)(va_arg(ptr, int)));
	else if (c == 's')
		sum += ft_putstr(va_arg(ptr, char *));
	else if (c == '%')
		sum += ft_putchar('%');
	else if (c == 'd' || c == 'i')
		sum += ft_putnbr((int)(va_arg(ptr, int)));
	else if (c == 'u')
		sum += ft_putnbr_u((unsigned int)(va_arg(ptr, int)));
	else if (c == 'x')
		sum += ft_putnbr_hex((unsigned int)(va_arg(ptr, int)), 'x');
	else if (c == 'X')
		sum += ft_putnbr_hex((unsigned int)(va_arg(ptr, int)), 'X');
	else if (c == 'p')
	{
		sum += ft_putstr("0x");
		sum += ft_putnbr_p((unsigned long)(va_arg(ptr, char *)));
	}
	else
		sum += ft_putchar(c);
	return (sum);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		sum;

	sum = 0;
	va_start(ptr, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			sum += formattt(ptr, str[i + 1]);
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == '\0')
			break ;
		else
			sum += ft_putchar(str[i]);
		i++;
	}
	va_end(ptr);
	return (sum);
}
