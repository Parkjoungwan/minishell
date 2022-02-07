/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argumentscheck_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:06:52 by joupark           #+#    #+#             */
/*   Updated: 2022/01/13 11:35:58 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell0"

static int ft_set_input(t_split *content, int i, int flag)
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

static int	ft_set_output(t_split *content, int i, int flag)
{
	if (!content->tokens[i + 1])
		return (-666);
	if (flag)
		content->appo = 1;
	else
		content->redo = 1;
	if (!content->oname)
		content->oname = ft_strdup(content->tokens[i + 1]);
	free(content->tokens[i]);
	free(content->tokens[i + 1]);
	content->tokens[i] = NULL;
	content->tokens[i + 1] = NULL;
	return (i);

}

int	ft_checktoken_input(t_split *content, int i)
{
	if (!content->tokens[i])
		return (i);
	if (!ft_strncmp(content->tokens[i], "<<", 3))
	{
		i = ft_set_input(content, i, 1);
		return (i + 1);
	}
	else if (!ft_strncmp(content->tokens[i], "<", 2))
	{
		i = ft_set_input(content, i, 0);
		return (i + 1);
	}
	return (i);
}

int	ft_checktoken_output(t_split *content, int i)
{
	if (!content->tokens[i])
		return (i);
	if (!ft_strncmp(content->tokens[i], ">>", 3))
	{
		i = ft_set_output(content, i, 1);
		return (i + 1);
	}
	else if (!ft_strncmp(content->tokens[i], ">", 2))
	{
		i = ft_set_output(content, i, 0);
		return (i + 1);
	}
	return (i);
}
