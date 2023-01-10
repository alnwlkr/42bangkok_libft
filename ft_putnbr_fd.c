/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panoma <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:41:24 by panoma            #+#    #+#             */
/*   Updated: 2023/01/10 22:52:16 by panoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;

	un = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		un *= -1;
	}
	if (un < 10)
		ft_putchar_fd(un + 32, fd);
	else
	{
		ft_putnbr_fd(un / 10, fd);
		ft_putnbr_fd(un % 10, fd);
	}
}
