/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeexec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:46:27 by joupark           #+#    #+#             */
/*   Updated: 2022/02/07 10:57:39 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	**get_argv(t_split *cmdinfo, char *name)
{
	int		i;
	int		max;
	char	**argv;

	max = 0;
	//뒤에 NULL 2개다.
	while (cmdinfo->tokens[max] != NULL)
		max++;
	max++;
	argv = ft_calloc(max + 1, sizeof(char *));
	if (!argv)
		return (NULL);
	argv[0] = ft_strdup(name);
	i = 1;
	while (cmdinfo->tokens[i] != NULL)
	{
		if (ft_strlen(cmdinfo->tokens[i]))
			argv[i] = ft_strdup(cmdinfo->tokens[i]);
		else
			argv[i] = ft_calloc(1, sizeof(char));
		i++;
	}
	argv[i] = NULL;
	return (argv);
}

void	close_one_pipe(t_split *cmdinfo)
{
	int in;

	if (cmdinfo->piped < 1)
		return ;
	in = cmdinfo->pipenbr * 2;
	if (!cmdinfo->pipenbr)
		close(cmdinfo->pipefd[1]);
	else if (cmdinfo->pipenbr > 0 && cmdinfo->pipenbr != cmdinfo->piped)
	{
		close(cmdinfo->pipefd[in + 1]);
		close(cmdinfo->pipefd[in - 2]);
	}
	else if (cmdinfo->pipenbr == cmdinfo->piped)
	{
		close(cmdinfo->pipefd[in - 2]);
		free(cmdinfo->pipefd);
	}
}

void	close_pipes(t_split *cmdinfo)
{
	int	in;
	int i;

	if (cmdinfo->piped < 1)
		return ;
	in = cmdinfo->piped * 2 + 1;
	i = 0;
	while (i <= in)
	{
		close(cmdinfo->pipefd[i]);
		i++;
	}
}

void	ft_pipe_exec(char *name, t_list **envhead, t_split *cmdinfo)
{
	int	in;
	int	err;

	err = 0;
	if (cmdinfo->piped < 1)
		err = execve(name, get_argv(cmdinfo, name), ft_exportenv(envhead));
	else
	{
		in = cmdinfo->pipenbr * 2;
		if (!cmdinfo->redo && !cmdinfo->appo && cmdinfo->pipenbr != cmdinfo->piped)
			dup2(cmdinfo->pipefd[in + 1], STDOUT_FILENO);
		if (!cmdinfo->redi && !cmdinfo->appi && cmdinfo->pipenbr > 0)
			dup2(cmdinfo->pipefd[in - 2], STDIN_FILENO);
		err = execve(name, get_argv(cmdinfo, name), ft_exportenv(envhead));
		close_pipes(cmdinfo);
	}
	if (err)
		exit(errno);
}
