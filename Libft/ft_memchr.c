/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 14:17:08 by joupark           #+#    #+#             */
/*   Updated: 2022/01/05 10:38:35 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memchr(const void *b, int c, size_t len)
{
	unsigned char	*temp_b;

	temp_b = (unsigned char *)b;
	while (len--)
	{
		if (*temp_b == (unsigned char)c)
			return ((void *)temp_b);
		temp_b++;
	}
	return (0);
}
