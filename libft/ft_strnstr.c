/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbachir <cbachir@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:43:42 by cbachir           #+#    #+#             */
/*   Updated: 2021/10/05 21:33:58 by cbachir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*a;
	char	*b;
	size_t	len_need;

	if (!*needle)
		return ((char *)haystack);
	len_need = ft_strlen(needle);
	if (!ft_strlen(haystack) || len < len_need)
		return (0);
	len -= --len_need;
	while (len-- && *haystack)
	{
		a = (char *)haystack;
		b = (char *)needle;
		while (*b && *a == *b)
		{
			++a;
			++b;
		}
		if (*b == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
