/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makecmdlst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:12:51 by joupark           #+#    #+#             */
/*   Updated: 2022/01/12 14:26:28 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_tokensnum(char **matrix, int i)
{
	int num;

	num = 0;
	while (matrix && matrix[i])
	{
		if (!ft_strncmp(matrix[i], "|\0", 2))
			break ;
		if (ft_strlen(matrix[i]))
			num++;
		i++;
	}
	return (num);
}

static void	ft_cpytokens(char **matrix, char **new, int i, int n)
{
	int j;

	j = 0;
	if (!new)
		return ;
	while (j < n && matrix[i + j])
	{
		if (matrix[i + j][0] == '\"')
			new[j] = ft_strtrim(matrix[i + j], "\"");
		else
			new[j] = ft_strtrim(matrix[i + j], "\'");
		free(matrix[i + j]);
		j++;
	}
	new[j] = NULL;
}

void		ft_makecmdlst(char **matrix, t_list **lsthead)
{
	t_split	*content;
	int		i;
	int		num;

	i = 0;
	while (matrix && matrix[i])
	{
		num = ft_tokensnum(matrix, i);
		if (num)
		{
			content = ft_calloc(1, sizeof(t_split));
			if (!content)
				return ;
			content->tokens = ft_calloc(num + 1, sizeof(char *));
			ft_cpytokens(matrix, content->tokens, i, num);
			ft_lstadd_back(lsthead, ft_lstnew(content));
			i += num;
		}
		else
		{
			free(matrix[i]);
			i++;
		}
	}
}
