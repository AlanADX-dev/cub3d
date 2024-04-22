/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaduel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:33:19 by hbaduel           #+#    #+#             */
/*   Updated: 2023/12/11 17:33:21 by hbaduel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count ++;
		i++;
	}
	return (count);
}

static int	ft_wordlen(char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

char	**ft_split(char *s, char c)
{
	char	**tab;
	int		i;
	int		wc;

	if (!s)
		return (NULL);
	wc = ft_wordcount(s, c);
	tab = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < wc)
	{
		while (*s == c)
			s++;
		tab[i] = ft_substr(s, 0, ft_wordlen(s, c));
		if (!tab[i])
			return (NULL);
		s += ft_wordlen(s, c);
		i++;
	}
	tab[i] = (NULL);
	return (tab);
}
