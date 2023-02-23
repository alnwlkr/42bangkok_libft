/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panoma <panoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 00:44:08 by panoma            #+#    #+#             */
/*   Updated: 2023/02/22 19:48:49 by panoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	ndlen;

	if (*needle == 0)
	{
		return ((char *) haystack);
	}
	ndlen = ft_strlen(needle);
	i = 0;
	while (i < len && haystack[i])
	{
		if (haystack[i] == *needle && len - i >= ndlen)
		{
			if (ft_strncmp(&haystack[i], needle, ndlen) == 0)
				return ((char *) &haystack[i]);
		}
		i++;
	}
	return (NULL);
}
