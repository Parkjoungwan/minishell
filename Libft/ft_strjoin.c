/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 12:37:00 by joupark           #+#    #+#             */
/*   Updated: 2021/01/01 11:59:15 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = (char *)ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (new == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (i < s1_len)
	{
		new[i] = s1[i];
		i++;
	}
	while (j < s2_len)
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}
