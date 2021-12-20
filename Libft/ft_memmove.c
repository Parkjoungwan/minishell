/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:44:13 by joupark           #+#    #+#             */
/*   Updated: 2020/12/27 20:01:25 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	if (len == 0 || dst == src)
		return (dst);
	if (dst < src)
	{
		temp_dst = (unsigned char *)dst;
		temp_src = (unsigned char *)src;
		while (len--)
			*temp_dst++ = *temp_src++;
	}
	else
	{
		temp_dst = (unsigned char *)dst + (len - 1);
		temp_src = (unsigned char *)src + (len - 1);
		while (len--)
			*temp_dst-- = *temp_src--;
	}
	return (dst);
}
