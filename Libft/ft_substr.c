/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 11:34:25 by joupark           #+#    #+#             */
/*   Updated: 2020/12/31 22:24:05 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	s_len;

	if (s == 0)
		return (NULL);
	new = (char *)ft_calloc(len + 1, sizeof(char));
	if (new == 0)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
		return (new);
	ft_strlcpy(new, s + start, len + 1);
	return (new);
}
