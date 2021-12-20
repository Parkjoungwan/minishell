/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 11:22:13 by joupark           #+#    #+#             */
/*   Updated: 2021/01/03 13:09:33 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_free_all(char **result)
{
	size_t	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

static	size_t	ft_num_strs(char const *s, char c)
{
	size_t	i;
	size_t	result;

	if (!s[0])
		return (0);
	i = 0;
	result = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			result++;
			while (s[i] && s[i] == c)
				i++;
			continue;
		}
		i++;
	}
	if (s[i - 1] != c)
		result++;
	return (result);
}

static	void	ft_num_str(char **str, size_t *str_len, char c)
{
	size_t	i;

	*str += *str_len;
	*str_len = 0;
	i = 0;
	while (**str && **str == c)
		(*str)++;
	while ((*str)[i])
	{
		if ((*str)[i] == c)
			return ;
		(*str_len)++;
		i++;
	}
}

char			**ft_split(char const *s, char c)
{
	char	**result;
	char	*temp_str;
	size_t	temp_len;
	size_t	num_strs;
	size_t	i;

	if (!s)
		return (NULL);
	num_strs = ft_num_strs(s, c);
	if (!(result = malloc(sizeof(char *) * (num_strs + 1))))
		return (NULL);
	temp_str = (char *)s;
	temp_len = 0;
	i = 0;
	while (i < num_strs)
	{
		ft_num_str(&temp_str, &temp_len, c);
		if (!(result[i] = malloc(sizeof(char) * (temp_len + 1))))
			return (ft_free_all(result));
		ft_strlcpy(result[i], temp_str, temp_len + 1);
		i++;
	}
	result[i] = NULL;
	return (result);
}
