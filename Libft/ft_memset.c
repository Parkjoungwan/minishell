/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 10:20:15 by joupark           #+#    #+#             */
/*   Updated: 2022/01/05 10:40:03 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memset(void *dst, int c, size_t lenght)
{
	size_t	i;

	i = 0;
	while (i < lenght)
	{
		*((char *)dst + i) = c;
		i++;
	}
	return (dst);
}
