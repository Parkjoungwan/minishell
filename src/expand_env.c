/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:27:24 by joupark           #+#    #+#             */
/*   Updated: 2022/02/09 23:23:16 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_checksingle(char *str)
{
	if (ft_strlen(str) < 2)
		return (1);
	if (*str == '$' && *(str + 1) == '?')
		return (0);
	if (*str == '$' && ft_isalnum(*(str + 1)))
		return (0);
	return (1);
}

int	ft_findexit(char *str)
{
	int	result;

	result = 0;
	if (*str && *str == '?')
		return (1);
	while (*str && ft_isalnum(*str))
	{
		str++;
		result++;
	}
	return (result);
}

int	ft_findentry(char *str)
{
	int	result;

	result = 0;
	while (*str && *(str + 1) && ft_checksingle(str))
	{
		str++;
		result++;
	}
	return (result);
}

static void	ft_expanding(char **matrix, int i, t_list **envhead)
{
	char	*var;
	char	*new;
	char	*temp;
	int		entry;
	int		exit;

	entry = ft_findentry(matrix[i]);
	exit = ft_findexit(matrix[i] + entry + 1);
	var = ft_substr(matrix[i], entry + 1, exit);
	if (!ft_strlen(var))
	{
		free(var);
		return ;
	}
	temp = ft_getenv(*envhead, var);
	if (!temp)
		temp = "";
	new = ft_expandmake(matrix[i], temp, entry, exit);
	free(var);
	free(matrix[i]);
	matrix[i] = new;
}

void	ft_expand_env(char **matrix, t_list **envhead)
{
	int		i;
	int		cnt;
	char	*find;

	i = 0;
	while (matrix[i])
	{
		if (ft_expandcheck(matrix, i))
		{
			cnt = 0;
			find = matrix[i];
			while (find && *find)
			{
				if (*find == '$')
					cnt++;
				find++;
			}
			while (cnt)
			{
				ft_expanding(matrix, i, envhead);
				cnt--;
			}
		}
		i++;
	}
}
