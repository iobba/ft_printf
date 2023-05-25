/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:00:32 by iobba             #+#    #+#             */
/*   Updated: 2022/11/01 10:30:38 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_p(unsigned long nb)
{
	char	*hexa;
	int		sum;

	sum = 0;
	hexa = "0123456789abcdef";
	if (nb >= 0 && nb <= 9)
		sum += ft_putchar(nb + 48);
	else if (nb >= 10 && nb <= 15)
		sum += ft_putchar(nb + 87);
	else
	{
		sum += ft_putnbr_p(nb / 16);
		sum += ft_putchar(hexa[nb % 16]);
	}
	return (sum);
}
