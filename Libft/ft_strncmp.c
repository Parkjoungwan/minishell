/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 22:42:24 by joupark           #+#    #+#             */
/*   Updated: 2020/12/29 12:24:19 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_temp;
	unsigned char	*s2_temp;

	s1_temp = (unsigned char *)s1;
	s2_temp = (unsigned char *)s2;
	while (n--)
	{
		if (*s1_temp != *s2_temp || !(*s1_temp) || !(*s2_temp))
			return (*s1_temp - *s2_temp);
		s1_temp++;
		s2_temp++;
	}
	return (0);
}
