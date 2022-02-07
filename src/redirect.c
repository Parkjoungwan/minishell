/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:57:36 by joupark           #+#    #+#             */
/*   Updated: 2022/02/07 10:52:55 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_inputcon(t_list **envhead, t_split *cmdinfo)
{
	int	fd;

	fd = open(cmdinfo->iname, O_RDONLY, 0644);
	if (fd == -1)
	{
		ft_print_error(envhead, cmdinfo->iname, -1);
		return (1);
	}
	cmdinfo->fdin = dup(STDIN_FILENO);
	if (dup2(fd, STDIN_FILENO) == -1)
		ft_printf_error(envhead, "dup2", -1);
	if (cmdinfo->fdin == -1)
	{
		ft_print_error(envhead, "dup", -1);
		return (2);
	}
	return (0);
}

static int	ft_outputcon(t_list **envhead, t_split *cmdinfo)
{
	int fd;

	fd = 0;
	if (cmdinfo->redo == 1)
		fd = open(cmdinfo->oname, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	else if (cmdinfo->appo == 1)
		fd = open(cmdinfo->oname, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		ft_print_error(envhead, cmdinfo->oname, -1);
		return (1);
	}
	cmdinfo->fdout = dup(STDOUT_FILENO);
	if (dup2(fd, STDOUT_FILENO) == -1)
		ft_print_error(envhead, "dup2", -1);
	if (cmdinfo->fdout == -1)
	{
		ft_print_error(envhead, "dup", -1);
		return (2);
	}
	return (0);
}

int	ft_close_redirect(t_split *cmdinfo)
{
	int err;

	err = 0;
	if (cmdinfo->fdin > 0)
	{
		err = dup2(cmdinfo->fdin, STDIN_FILENO);
		close(cmdinfo->fdin);
	}
	if (cmdinfo->fdout > 0)
	{
		err = err | dup2(cmdinfo->fdout, STDIN_FILENO);
		close(cmdinfo->fdout);
	}
	if (cmdinfo->fdhere > 0)
	{
		err = err | dup2(cmdinfo->fdhere, STDIN_FILENO);
		close(cmdinfo->fdhere);
	}
	return (err);
}

int			ft_redirect(t_list **envhead, t_split *cmdinfo)
{
	int	err;

	err = 0;
	if (cmdinfo->redi)
		err = ft_inputcon(envhead, cmdinfo);
	if (!err && cmdinfo->appi)
		ft_doc_input(envhead, cmdinfo);
	if (!err && (cmdinfo->redo || cmdinfo->appo))
		err = err | ft_outputcon(envhead, cmdinfo);
	return (err);
}
