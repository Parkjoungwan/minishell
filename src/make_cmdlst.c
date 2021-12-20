/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmdlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:53:22 by joupark           #+#    #+#             */
/*   Updated: 2021/12/20 16:03:12 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int get_numbr_token(char **matrix, int i)
{
	int n;

	n = 0;
	while (matrix && matrix[i])
	{
		if (!ft_strncmp(matrix[i], "|\0", 2))
			break ;
		if (ft_strlen(matrix[i]))
			n++;
		i++;
	}
	return (n);
}

static void	cpy_tokens(char **matrix, char **new, int i, int n)
{
	int j;
	
	if (!new)
		return ;
	j = 0;
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

void	ms_populate_cmdlst(char	**matrix, t_list **lsthead)
{
	t_split	*content;
	int	i;
	int n;

	i = 0; 
	while (matrix && matrix[i])
	{
		n = get_numbr_token(matrix, i);
		if (n)
		{
			content = ft_calloc(1, sizeof(t_split));
			if (!content)
				return ;
			content->tokens = ft_calloc(n + 1, sizeof(char *));
			cpy_tokens(matrix, content->tokens, i, n);
			ft_lstadd_back(lsthead, ft_lstnew(content));
			i += n;
		}
		else
		{
			free(matrix[i]);
			i++;
		}
	}
}
