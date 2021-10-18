/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbachir <cbachir@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:50:37 by cbachir           #+#    #+#             */
/*   Updated: 2021/10/13 13:17:33 by cbachir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**to_free(char **pt)
{
	int	i;

	i = 0;
	while (pt[i])
	{
		free(pt[i]);
		i++;
	}
	free(pt);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s || ft_strlen(s) <= start || !len)
		return (ft_strdup(""));
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

static int	ft_wordlength(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

static int	ft_countwords(char const *str, char c)
{
	int	i;
	int	nb_words;

	i = 0;
	nb_words = 1;
	while (str[i] != '\0')
	{
		if ((str[i] == c && str[i + 1] != c))
			nb_words++;
		i++;
	}
	if (str[ft_strlen(str) - 1] == c)
		nb_words--;
	if (str[0] == c)
		nb_words--;
	return (nb_words);
}

char	**ft_split(char const *s, char c)
{
	char	**pt;
	int		i;
	int		t;

	i = 0;
	t = 0;
	if (!s)
		return (0);
	pt = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!pt)
		return (0);
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			pt[t] = ft_substr(s, i, ft_wordlength(&s[i], c));
			if (!pt[t])
				return (to_free(pt));
			i = i + ft_strlen(pt[t]) - 1;
			t++;
		}
		i++;
	}
	pt[t] = 0;
	return (pt);
}
