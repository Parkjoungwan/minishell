/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:23:45 by joupark           #+#    #+#             */
/*   Updated: 2022/02/07 11:00:35 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_isoperator(char *str)
{
	if (!(ft_strncmp(str, "|", 1)))
	{
		if (ft_isalnum(*(str + 1)))
			return (1);
	}
	if (!(ft_strncmp(str, ">>", 2)) || !(ft_strncmp(str, "<<", 2)))
	{
		if (ft_isalnum(*(str + 2)))
			return (1);
	}
	if (!(ft_strncmp(str, ">", 1)) || !(ft_strncmp(str, "<", 1)))
	{
		if (ft_isalnum(*(value + 1)))
			return (1);
	}
	return (0);
}
static char *ft_makenewline(char *line, char *curr, int operator_size, int offset)
{
	char	**temp;
	char	*result;
	int		i;

	temp = ft_calloc(6, sizeof(char *));
	if (!temp)
		return (NULL);
	temp[0] = ft_substr(line, 0, offset);
	temp[1] = ft_substr(curr, 0, operator_size);
	temp[2] = ft_strdup(curr + operator_size);
	temp[3] = ft_strjoin(help[0], " ");
	temp[4] = ft_strjoin(help[3], help[1]);
	temp[5] = ft_strjoin(help[4], " ");
	result = ft_strjoin(help[5], help[2]);
	i = 0;
	while (i < 6)
	{
		free(temp[i]);
		i++;
	}
	free(temp);
	return (result);
}

static char	*ft_addspace(char **line, char *curr, char *line_init)
{
	char	*new_line;
	int		operator_size;
	int		offset;

	if (curr != line_init)
		if (*(curr - 1) == '>' || *(curr - 1) == '<')
			return (curr++);
	if (*curr == *(curr + 1))
		operator_size = 2;
	else
		operator_size = 1;
	offset = curr - *line;
	new_line = ft_makenewline(*line, curr, operator_size, offset);
	free (*line);
	*line = new_line;
	return (new_line + offset + operator_size + 1);
}

void		ft_insertspace(char **line)
{
	char	*curr;
	char	*line_init;
	char	quote_found;

	curr = *line;
	line_init = *line;
	while (curr && *curr)
	{
		if ((*curr == '\'' && ft_strchr(curr + 1, '\''))
			|| ((*curr == '"' && ft_strchr(curr + 1, '"'))))
		{
			quote_found = *curr;
			curr++;
			while (*curr != quote_found)
				curr++;
		}
		if (ft_isoperator(curr))
			curr = ft_addspace(line, curr, line_init);
		curr++;
	}
}
