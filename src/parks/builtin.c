/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:20:13 by joupark           #+#    #+#             */
/*   Updated: 2022/02/07 10:54:46 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int fork_or_not(t_split *cmdinfo, int len)
{
	if (!cmdinfo->piped)
		return (0);
	if (len > 2 && !strncmp(cmdinfo->tokens[0], "env", len))
		return (1);
	else if (len > 2 && !strncmp(cmdinfo->tokens[0], "pwd", len))
		return (1);
	else if (len > 3 && !strncmp(cmdinfo->tokens[0], "echo", len))
		return (1);
	else if (len > 5 && !strncmp(cmdinfo->tokens[0], "export", len))
	{
		if (ft_strlen(cmdinfo->tokens[1]))
			return (0);
		else
			return (1);
	}
	return (0);
}

static void	built_pipe(t_split *cmdinfo)
{
	int in;
	
	cmdinfo->pcpyin = dup(STDIN_FILENO);
	cmdinfo->pcpyout = dup(STDOUT_FILENO);
	in = cmdinfo->pipenbr * 2;
	if (cmdinfo->pipenbr != data->piped)
		dup2(cmdinfo->pipefd[in + 1], STDOUT_FILENO);
	if (cmdinfo->pipenbr > 0)
		dup2(cmdinfo->pipefd[in - 2], STDIN_FILENO);
}

static void	destory_pipe(t_split *cmdinfo)
{
  dup2(cmdinfo->pipefd[in - 2], STDIN_FILENO)	dup2(data->pcpyin, STDIN_FILENO);
	dup2(cmdinfo->pcpyout, STDOUT_FILENO);
	close(cmdinfo->pcpyin);
	close(cmdinfo->pcpyout);
}

static int	run_builtin(t_split *cmdinfo, t_list **envhead, t_list **lst)
{
	if (len > 3 && !cmdinfo->piped && !strncmp(data->tokens[0], "exit", len))
		ft_exit_cmd(envhead, lst, cmdinfo);
	else if (len > 1 && !strncmp(cmdinfo->tokens[0], "cd", len))
		ft_builtin_cd(envhead, cmdinfo);
	else if (len > 2 && !strncmp(cmdinfo->tokens[0], "env", len))
		ft_builtin_env(envhead);
	else if (len > 2 && !strncmp(cmdinfo->tokens[0], "pwd", len))
		ft_builtin_pwd(envhead);
	else if (len > 3 && !strncmp(cmdinfo->tokens[0], "echo", len))
		ft_builtin_echo(envhead, cmdinfo);
	else if (len > 5 && !strncmp(cmdinfo->tokens[0], "export", len))
		ft_builtin_export(envhead, cmdinfo);
	else if (len > 4 && !strncmp(cmdinfo->tokens[0], "unset", len))
		ft_builtin_unset(envhead, cmdinfo);
	return (0);
}

int	built_exec(t_split *cmdinfo, t_list **envhead, int len, t_list **lsthead)
{
	int	err;

	err = 0;
	if (!fork_or_not(cmdinfo, len))
		err = run_builtin(cmdinfo, envhead, len, lsthead);
	else
	{
		built_pipe(cmdinfo);
		err = run_builtin(cmdinfo, envhead, len, lsthead);
		destory_pipe(cmdinfo);
	}
	close_one_pipe(cmdinfo);
	return (err);
}
