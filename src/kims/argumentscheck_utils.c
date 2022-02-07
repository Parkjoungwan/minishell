/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argumentscheck_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:06:52 by joupark           #+#    #+#             */
/*   Updated: 2022/02/07 11:04:51 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell0"

static int ft_set_input(t_split *cmdinfo, int i, int flag)
{
	if (!cmdinfo->tokens[i + 1])
		return (-666);
	if (flag)
		cmdinfo->appi = 1;
	else
		cmdinfo->redi = 1;
	if (!cmdinfo->iname)
		cmdinfo->iname = ft_strdup(content->tokens[i + 1]);
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
		cmdinfo->appo = 1;
	else
		cmdinfo->redo = 1;
	if (!cmdinfo->oname)
		cmdinfo->oname = ft_strdup(content->tokens[i + 1]);
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
