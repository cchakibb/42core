/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbachir <cbachir@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:16:39 by cbachir           #+#    #+#             */
/*   Updated: 2021/10/13 13:12:59 by cbachir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(long int n)
{
	int	len;

	len = 1;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*str_malloc(int len)
{
	char	*str;

	str = (char *)malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	return (str);
}

static char	*create_string(long int n, int len, int is_neg, char *s)
{
	if (n == 0)
	{
		*s = '0';
		return (s);
	}
	if (is_neg)
	{
		s[0] = '-';
		len++;
	}
	s[len] = 0;
	while (n > 0)
	{
		len--;
		s[len] = (n % 10) + 48;
		n /= 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		is_neg;
	int		len;
	char	*str;
	long	num;

	str = NULL;
	num = n;
	if (num < 0)
	{
		is_neg = 1;
		num = -num;
		len = get_length(num);
		str = str_malloc(len + 2);
		str = create_string(num, len, is_neg, str);
	}
	else
	{
		is_neg = 0;
		len = get_length(num);
		str = str_malloc(len + 1);
		str = create_string(num, len, is_neg, str);
	}
	return (str);
}
