/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:58:47 by joupark           #+#    #+#             */
/*   Updated: 2021/01/01 12:01:13 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_start(const char *s1, const char *set)
{
	size_t	s1_len;
	size_t	i;

	s1_len = ft_strlen(s1);
	i = 0;
	while (i < s1_len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

int		ft_end(const char *s1, const char *set)
{
	size_t	s1_len;
	size_t	i;

	s1_len = ft_strlen(s1);
	i = 0;
	while (i < s1_len)
	{
		if (ft_strchr(set, s1[s1_len - 1 - i]) == 0)
			break ;
		i++;
	}
	return (s1_len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*new;

	if (s1 == 0)
		return (NULL);
	if (set == 0)
		return (ft_strdup(s1));
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	new = ft_calloc(end - start + 1, sizeof(char));
	if (new == 0)
		return (NULL);
	ft_strlcpy(new, s1 + start, end - start + 1);
	return (new);
}
