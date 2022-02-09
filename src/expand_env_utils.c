/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:49:57 by joupark           #+#    #+#             */
/*   Updated: 2022/02/09 23:24:10 by joupark          ###   ########.fr       */
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

int	ft_expandcheck(char **matrix, int i)
{
	int	j;

	j = 0;
	while (matrix[i][j] && matrix[i][j] != '$' && matrix[i][j] != '"')
	{
		if (matrix[i][j] == '\'')
			return (0);
		j++;
	}
	return (1);
}

void	exp_var(char **matrix, int i, t_list **envhead)
{
	int		entry;
	int		exit;
	char	*var;
	char	*new;
	char	*tmp;

	entry = ft_findentry(matrix[i]);
	exit = ft_findexit(matrix[i] + entry + 1);
	var = ft_substr(matrix[i], entry + 1, exit);
	if (!ft_strlen(var))
	{
		free(var);
		return ;
	}
	tmp = ft_getenv(*envhead, var);
	if (!tmp)
		tmp = "";
	new = ft_expandmake(matrix[i], tmp, entry, exit);
	free(var);
	free(matrix[i]);
	matrix[i] = new;
}
