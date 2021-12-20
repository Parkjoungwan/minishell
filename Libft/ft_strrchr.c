/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 22:11:27 by joupark           #+#    #+#             */
/*   Updated: 2020/12/29 20:42:59 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	temp_c;
	size_t	size;

	size = ft_strlen(s);
	last = (char *)(s + size - 1);
	temp_c = (char)c;
	if ((char)c == '\0')
		return ((char *)(s + size));
	while (size > 0)
	{
		if (*last == temp_c)
			return (last);
		last--;
		size--;
	}
	if (*last == temp_c)
		return (last);
	return (0);
}
