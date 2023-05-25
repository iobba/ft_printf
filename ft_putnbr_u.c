/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:02:44 by iobba             #+#    #+#             */
/*   Updated: 2022/11/01 09:17:39 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_u(unsigned int nb)
{
	int	sum;

	sum = 0;
	if (nb >= 0 && nb <= 9)
		sum += ft_putchar(nb + 48);
	else
	{
		sum += ft_putnbr_u(nb / 10);
		sum += ft_putchar((nb % 10) + 48);
	}
	return (sum);
}
