/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makecmdlst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:12:51 by joupark           #+#    #+#             */
/*   Updated: 2022/02/09 16:10:44 by joupark          ###   ########.fr       */
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

static int	is_fake_redirect(char *str)
{
	if (!(ft_strncmp(str, "\">>\"", 4)) || !(ft_strncmp(str, "\"<<\"", 4)))
		return (1);
	if (!(ft_strncmp(str, "\">\"", 3)) || !(ft_strncmp(str, "\"<\"", 3)))
		return (1);
	if (!(ft_strncmp(str, "\'>>\'", 4)) || !(ft_strncmp(str, "\'<<\'", 4)))
		return (1);
	if (!(ft_strncmp(str, "\'>\'", 3)) || !(ft_strncmp(str, "\'<\'", 3)))
		return (1);
	return (0);
}

static void	ft_cpytokens(char **matrix, char **tokens, int i, int num)
{
	int j;

	j = 0;
	if (!tokens)
		return ;
	while (j < num && matrix[i + j])
	{
		if (matrix[i + j][0] == '\"')
		{
			tokens[j] = ft_strtrim(matrix[i + j], "\"");
			if(is_fake_redirect(matrix[i + j]))
				tokens[j] = ft_strjoin(tokens[j], "+-+");
		}
		else
		{
			tokens[j] = ft_strtrim(matrix[i + j], "\'");
			if(is_fake_redirect(matrix[i + j]))
				tokens[j] = ft_strjoin(tokens[j], "+-+");
		}
		free(matrix[i + j]);
		j++;
	}
	tokens[j] = NULL;
}

void		ft_makecmdlst(char **matrix, t_list **lsthead)
{
	t_split	*cmdinfo;
	int		i;
	int		num;

	i = 0;
	while (matrix && matrix[i]) //누수체크
	{
		num = ft_tokensnum(matrix, i);
		if (num)
		{
			cmdinfo = ft_calloc(1, sizeof(t_split));
			if (!cmdinfo)
				return ;
			cmdinfo->tokens = ft_calloc(num + 1, sizeof(char *));
			ft_cpytokens(matrix, cmdinfo->tokens, i, num);
			ft_lstadd_back(lsthead, ft_lstnew(cmdinfo));
			i += num;
		}
		else
		{
			free(matrix[i]);
			i++;
		}
	}
}
