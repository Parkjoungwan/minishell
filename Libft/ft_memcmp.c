/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 14:54:38 by joupark           #+#    #+#             */
/*   Updated: 2020/12/27 19:56:31 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	unsigned char	*temp_b1;
	unsigned char	*temp_b2;
	size_t			i;

	temp_b1 = (unsigned char *)b1;
	temp_b2 = (unsigned char *)b2;
	i = 0;
	while (i < len)
	{
		if (*(temp_b1 + i) != *(temp_b2 + i))
			return (*(temp_b1 + i) - *(temp_b2 + i));
		i++;
	}
	return (0);
}
