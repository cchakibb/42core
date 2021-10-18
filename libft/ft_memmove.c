/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbachir <cbachir@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:55:22 by cbachir           #+#    #+#             */
/*   Updated: 2021/10/13 12:50:24 by cbachir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	void	*ret;

	if (!dest && !src)
		return (0);
	ret = dest;
	if (src < dest)
	{
		dest += len;
		src += len;
		while (len--)
			*(char *)--dest = *(char *)--src;
	}
	else
	{
		while (len--)
			*(char *)dest++ = *(char *)src++;
	}
	return (ret);
}
