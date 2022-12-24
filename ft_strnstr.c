/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panoma <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 00:44:08 by panoma            #+#    #+#             */
/*   Updated: 2022/12/16 01:59:10 by panoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	ndlen;

	if (!needle || *needle == 0)
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
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	const char *s1 = "Hello, World!";
	const char *s2 = NULL;
	printf("%s\n", ft_strnstr(s1, s2, 12));
	//printf("%s\n", (char *) (strnstr(s1, s2, 12)));
	return (0);
}
*/
