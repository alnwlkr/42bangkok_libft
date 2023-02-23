/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panoma <panoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:32:12 by panoma            #+#    #+#             */
/*   Updated: 2023/02/22 18:06:21 by panoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_isin(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		front;
	int		back;

	if (!s1 || !set)
		return (NULL);
	front = 0;
	back = ft_strlen(s1) - 1;
	while (s1[front] && ft_isin(s1[front], set))
		front++;
	while (s1[back] && ft_isin(s1[back], set) && back >= 1)
	{
		back--;
		if (back == -1)
			break ;
	}
	if (back == -1)
		return (ft_substr(s1, front, 0));
	return (ft_substr(s1, front, (back - front + 1)));
}

/*
	char	*res;
*/
