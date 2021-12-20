/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:46:47 by joupark           #+#    #+#             */
/*   Updated: 2020/12/27 19:45:00 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*temp_src;
	size_t	i;

	if (!dest && !src)
		return (0);
	temp_src = (void *)src;
	i = 0;
	while (i < n)
	{
		*((char *)dest + i) = *((char *)temp_src + i);
		i++;
	}
	return (dest);
}
