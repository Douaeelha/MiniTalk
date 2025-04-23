/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delhajou <delhajou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 01:32:43 by delhajou          #+#    #+#             */
/*   Updated: 2025/03/23 01:46:56 by delhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
void ft_putchar(char c)
{
    write(1, &c,1);
}
int	ft_atoi(char *str)
{
	int	i;
	int	count;
	int	result;

	result = 0;
	i = 0;
	count = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) 
		i++; 
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			count++; 
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (count % 2 == 0)
		return (result);
	else 
		return (-result);
}
void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else if (nb >= 0 && nb <= 9)
		ft_putchar(nb + '0');
	else if (nb > 9)
	{
		ft_putnbr((nb / 10));
		ft_putnbr((nb % 10));
	}
}