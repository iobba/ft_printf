/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:21:51 by iobba             #+#    #+#             */
/*   Updated: 2022/11/01 09:23:44 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	sum;

	sum = 0;
	if (nb >= 0 && nb <= 9)
		sum += ft_putchar(nb + 48);
	else if (nb > 9)
	{
		sum += ft_putnbr(nb / 10);
		sum += ft_putchar((nb % 10) + 48);
	}
	else if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		sum += 11;
	}
	else
	{
		sum += ft_putchar('-');
		sum += ft_putnbr(nb * (-1));
	}
	return (sum);
}
