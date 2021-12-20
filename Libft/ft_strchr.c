/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 21:07:32 by joupark           #+#    #+#             */
/*   Updated: 2020/12/27 19:45:33 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *src, int c)
{
	char	temp_c;
	char	*temp_src;

	temp_c = (char)c;
	temp_src = (char *)src;
	while (*temp_src)
	{
		if (*temp_src == temp_c)
			return (temp_src);
		temp_src++;
	}
	if (*temp_src == temp_c)
		return (temp_src);
	return (0);
}
