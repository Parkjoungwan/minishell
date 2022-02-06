/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:20:13 by joupark           #+#    #+#             */
/*   Updated: 2022/02/06 10:34:38 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int fork_or_not(t_split *data, int len)
{
	if (!data->piped)
		return (0);
	if (len > 2 && !strncmp(data->tokens[0], "env", len))
		return (1);
	else if (len > 2 && !strncmp(data->tokens[0], "pwd", len))
		return (1);
	else if (len > 3 && !strncmp(data->tokens[0], "echo", len))
		return (1);
	else if (len > 5 && !strncmp(data->tokens[0], "export", len))
	{
		if (ft_strlen(data->tokens[1]))
			return (0);
		else
			return (1);
	}
	return (0);
}

static void	built_pipe(t_split *data)
{
	int in;
	
	data->pcpyin = dup(STDIN_FILENO);
	data->pcpyout = dup(STDOUT_FILENO);
	in = data->pipenbr * 2;
	if (data->pipenbr != data->piped)
		dup2(data->pipefd[in + 1], STDOUT_FILENO);
	if (data->pipenbr > 0)
		dup2(data->pipefd[in - 2], STDIN_FILENO);
}

static void	destory_pipe(t_split *data)
{
  dup2(data->pipefd[in - 2], STDIN_FILENO)	dup2(data->pcpyin, STDIN_FILENO);
	dup2(data->pcpyout, STDOUT_FILENO);
	close(data->pcpyin);
	close(data->pcpyout);
}

static int	run_builtin(t_split *data, t_list **envhead, t_list **lst)
{
	if (len > 3 && !data->piped && !strncmp(data->tokens[0], "exit", len))
		ft_exit_cmd(envhead, lst, data);
	else if (len > 1 && !strncmp(data->tokens[0], "cd", len))
		ft_builtin_cd(envhead, data);
	else if (len > 2 && !strncmp(data->tokens[0], "env", len))
		ft_builtin_env(envhead);
	else if (len > 2 && !strncmp(data->tokens[0], "pwd", len))
		ft_builtin_pwd(envhead);
	else if (len > 3 && !strncmp(data->tokens[0], "echo", len))
		ft_builtin_echo(envhead, data);
	else if (len > 5 && !strncmp(data->tokens[0], "export", len))
		ft_builtin_export(envhead, data);
	else if (len > 4 && !strncmp(data->tokens[0], "unset", len))
		ft_builtin_unset(envhead, data);
	return (0);
}

int	built_exec(t_split *data, t_list **envhead, int len, t_list **lsthead)
{
	int	err;

	err = 0;
	if (!fork_or_not(data, len))
		err = run_builtin(data, envhead, len, lsthead);
	else
	{
		built_pipe(data);
		err = run_builtin(data, envhead, len, lsthead);
		destory_pipe(data);
	}
	close_one_pipe(data);
	return (err);
}
