/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:22:48 by joupark           #+#    #+#             */
/*   Updated: 2021/12/20 16:33:20 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ms_set_ctti(t_split *content, int i, int flag)
{
	if (!content->tokens[i + 1])
		return (-666);
	if (flag)
		content->appi = 1;
	else
		content->redi = 1;
	if (!content->iname)
		content->iname = ft_strdup(content->tokens[i + 1]);
	free(content->tokens[i]);
	free(content->tokens[i + 1]);
	content->tokens[i] = NULL;
	content->tokens[i + 1] = NULL;
	return (i);
}

int ms_set_ctto(t_split *content, int i, int flag)
{
	if (!content->tokens[i + 1])
		return (-666);
	if (flag)
		content->appo = 1;
	else
		content->redo = 1;
	if (content->oname)
		free(content->oname);
	content->oname = ft_strdup(content->tokens[i + 1]);
	free(content->tokens[i]);
	free(content->tokens[i + 1]);
	content->tokens[i] = NULL;
	content->tokens[i + 1] = NULL;
	return (i);
}

int	ms_check_token_output(t_split *content, int i)
{
	if (!content->tokens[i])
		return (i);
	if (!ft_strncmp(content->tokens[i], ">>", 3))
	{
		i = ms_set_ctto(content, i, 1);
		return (i + 1);
	}
	else if (!ft_strncmp(content->tokens[i], ">", 2))
	{
		i = ms_set_ctto(content, i, 0);
		return (i + 1);
	}
	return (i);
}

int ms_check_token_input(t_split *content, int i)
{
	if (!content->tokens[i])
		return (i);
	if (!ft_strncmp(content->tokens[i], "<<", 3))
	{
		i = ms_set_ctti(content, i, 1);
		return (i + 1);
	}
	else if (!ft_strncmp(content->tokens[i], "<", 2))
	{
		i = ms_set_ctti(content, i, 0);
		return (i + 1);
	}
	return (i);
}
