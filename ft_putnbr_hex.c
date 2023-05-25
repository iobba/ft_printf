/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:02:38 by iobba             #+#    #+#             */
/*   Updated: 2022/11/01 10:48:45 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int nb, char c)
{
	char	*hexa;
	int		sum;

	sum = 0;
	hexa = "0123456789abcdef";
	if (nb >= 0 && nb <= 9)
		sum += ft_putchar(nb + 48);
	else if (nb >= 10 && nb <= 15)
		sum += ft_putchar((nb + 87) - ('x' - c));
	else
	{
		sum += ft_putnbr_hex(nb / 16, c);
		if (nb % 16 >= 10)
			sum += ft_putchar((hexa[nb % 16]) - ('x' - c));
		else
			sum += ft_putchar(hexa[nb % 16]);
	}
	return (sum);
}
