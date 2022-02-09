/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argumentscheck_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:06:52 by joupark           #+#    #+#             */
/*   Updated: 2022/02/09 23:07:08 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_set_input(t_split *cmdinfo, int i, int flag)
{
	if (!cmdinfo->tokens[i + 1])
		return (-666);
	if (flag)
		cmdinfo->twoi = 1;
	else
		cmdinfo->onei = 1;
	if (!cmdinfo->iname)
		cmdinfo->iname = ft_strdup(cmdinfo->tokens[i + 1]);
	free(cmdinfo->tokens[i]);
	free(cmdinfo->tokens[i + 1]);
	cmdinfo->tokens[i] = NULL;
	cmdinfo->tokens[i + 1] = NULL;
	return (i);
}

static int	ft_set_output(t_split *cmdinfo, int i, int flag)
{
	if (!cmdinfo->tokens[i + 1])
		return (-666);
	if (flag)
		cmdinfo->twoo = 1;
	else
		cmdinfo->oneo = 1;
	if (!cmdinfo->oname)
		cmdinfo->oname = ft_strdup(cmdinfo->tokens[i + 1]);
	free(cmdinfo->tokens[i]);
	free(cmdinfo->tokens[i + 1]);
	cmdinfo->tokens[i] = NULL;
	cmdinfo->tokens[i + 1] = NULL;
	return (i);
}

int	ft_checktoken_input(t_split *cmdinfo, int i)
{
	if (!cmdinfo->tokens[i])
		return (i);
	if (!ft_strncmp(cmdinfo->tokens[i], "<<", 3))
	{
		i = ft_set_input(cmdinfo, i, 1);
		return (i + 1);
	}
	else if (!ft_strncmp(cmdinfo->tokens[i], "<", 2))
	{
		i = ft_set_input(cmdinfo, i, 0);
		return (i + 1);
	}
	return (i);
}

int	ft_checktoken_output(t_split *cmdinfo, int i)
{
	if (!cmdinfo->tokens[i])
		return (i);
	if (!ft_strncmp(cmdinfo->tokens[i], ">>", 3))
	{
		i = ft_set_output(cmdinfo, i, 1);
		return (i + 1);
	}
	else if (!ft_strncmp(cmdinfo->tokens[i], ">", 2))
	{
		i = ft_set_output(cmdinfo, i, 0);
		return (i + 1);
	}
	return (i);
}
