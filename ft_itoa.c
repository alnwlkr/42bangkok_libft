/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panoma <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 02:23:42 by panoma            #+#    #+#             */
/*   Updated: 2023/01/05 03:16:19 by panoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_len_neg(int n, int *len, int *neg)
{
	if (n <= 0)
	{
		if (n < 0)
			*neg *= -1;
		(*len)++;
	}
	while (n)
	{
		n /= 10;
		(*len)++;
	}
}

static char	*ft_strr(char *s)
{
	char	temp;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char			*a;
	int				len;
	int				neg;
	int				i;
	unsigned int	num;

	len = 0;
	neg = 1;
	i = 0;
	ft_itoa_len_neg(n, &len, &neg);
	a = malloc(sizeof(char) * (len + 1));
	if (!a)
		return (NULL);
	if (n == 0)
		a[i++] = '0';
	num = n * neg;
	while (num)
	{
		a[i++] = (num % 10) + '0';
		num /= 10;
	}
	if (neg == -1)
		a[i++] = '-';
	a[i] = 0;
	return (ft_strr(a));
}
