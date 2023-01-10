/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panoma <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:01:46 by panoma            #+#    #+#             */
/*   Updated: 2023/01/10 22:21:59 by panoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	l;

	if (!s)
		return ;
	l = ft_strlen(s);
	write(fd, s, l);
}

/*
	while (*s)
		ft_putchar_fd(*(s++), fd);
*/
