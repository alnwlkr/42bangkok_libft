/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panoma <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:43:39 by panoma            #+#    #+#             */
/*   Updated: 2022/12/27 22:03:03 by panoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_2d_arr(char **words)
{
	size_t	i;

	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
	return (NULL);
}

static int	ft_word_count(const char *s, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			word_count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (word_count);
}

static char	*ft_get_word(const char *s1, int *index, char c)
{
	char	*temp;
	size_t	word_len;
	int		i;

	word_len = 0;
	while (s1[*index] == c)
		(*index)++;
	i = *index;
	while (s1[i] && s1[i] != c)
	{
		word_len++;
		i++;
	}
	temp = malloc(sizeof(char) * (word_len + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (s1[*index] && s1[*index] != c)
		temp[i++] = s1[(*index)++];
	temp[i] = '\0';
	return (temp);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		word_count;
	int		index;
	int		i;

	index = 0;
	i = 0;
	if (!s)
		return (NULL);
	word_count = ft_word_count(s, c);
	words = malloc(sizeof(char *) * (word_count + 1));
	if (!words)
		return (NULL);
	while (i < word_count)
	{
		words[i] = ft_get_word(s, &index, c);
		if (!words[i])
			return (ft_free_2d_arr(words));
		i++;
	}
	words[i] = 0;
	return (words);
}
/*
int	main(void)
{
	char	**res;
	size_t		i = 0;

	res = ft_split("  fizzabuzzafizzabuzz      ", 'a');
	while (i < ft_strlen((const char *) res) - 1)
	{
		printf("[%s] ", res[i]);
		i++;
	}
	printf("\n");
}
*/
