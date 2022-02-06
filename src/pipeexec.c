/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeexec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:46:27 by joupark           #+#    #+#             */
/*   Updated: 2022/02/06 12:59:46 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	**get_argv(t_split *data, char *name)
{
	int		i;
	int		max;
	char	**argv;

	max = 0;
	//뒤에 NULL 2개다.
	while (data->tokens[max] != NULL)
		max++;
	max++;
	argv = ft_calloc(max + 1, sizeof(char *));
	if (!argv)
		return (NULL);
	argv[0] = ft_strdup(name);
	i = 1;
	while (data->tokens[i] != NULL)
	{
		if (ft_strlen(data->tokens[i]))
			argv[i] = ft_strdup(data->tokens[i]);
		else
			argv[i] = ft_calloc(1, sizeof(char));
		i++;
	}
	argv[i] = NULL;
	return (argv);
}

void	close_one_pipe(t_split *data)
{
	int in;

	if (data->piped < 1)
		return ;
	in = data->pipenbr * 2;
	if (!data->pipenbr)
		close(data->pipefd[1]);
	else if (data->pipenbr > 0 && data->pipenbr != data->piped)
	{
		close(data->pipefd[in + 1]);
		close(data->pipefd[in - 2]);
	}
	else if (data->pipenbr == data->piped)
	{
		close(data->pipefd[in - 2]);
		free(data->pipefd);
	}
}

void	close_pipes(t_split *data)
{
	int	in;
	int i;

	if (data->piped < 1)
		return ;
	in = data->piped * 2 + 1;
	i = 0;
	while (i <= in)
	{
		close(data->pipefd[i]);
		i++;
	}
}

void	ft_pipe_exec(char *name, t_list **envhead, t_split *data)
{
	int	in;
	int	err;

	err = 0;
	if (data->piped < 1)
		err = execve(name, get_argv(data, name), ft_exportenv(envhead));
	else
	{
		in = data->pipenbr * 2;
		if (!data->redo && !data->appo && data->pipenbr != data->piped)
			dup2(data->pipefd[in + 1], STDOUT_FILENO);
		if (!data->redi && !data->appi && data->pipenbr > 0)
			dup2(data->pipefd[in - 2], STDIN_FILENO);
		err = execve(name, get_argv(data, name), ft_exportenv(envhead));
		close_pipes(data);
	}
	if (err)
		exit(errno);
}
