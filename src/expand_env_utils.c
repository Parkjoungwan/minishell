/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:49:57 by joupark           #+#    #+#             */
/*   Updated: 2022/01/12 14:10:20 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_expandmake(char *str, char *insert, int entry, int exit)
{
	char	*new;
	int		len;

	len = ft_strlen(str);
	if (insert)
		len += ft_strlen(insert);
	else
	{
		new = ft_calloc(len + 1, sizeof(char));
		ft_strlcpy(new, str, entry);
		ft_strlcpy(new, str + entry + exit + 1, len);
		return (new);
	}
	new = ft_calloc(len + 1, sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, str, entry + 1);
	ft_strlcat(new, insert, ft_strlen(new) + ft_strlen(insert) + 1);
	ft_strlcat(new, str + entry + exit + 1, len);
	return (new);
}

int		ft_expandcheck(char **matrix, int i)
{
	int j;

	j = 0;
	while (matrix[i][j] && matrix[i][j] != '$' && matrix[i][j] != '"')
	{
		if (matrix[i][j] == '\'')
			return (0);
		j++;
	}
	return (1);
}
