/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:20:47 by joupark           #+#    #+#             */
/*   Updated: 2022/02/06 11:19:06 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*ft_getpath(t_list **envhead)
{
	char	*path;

	path = ft_getenv(*envhead, "PATH");
	if (path)
		return (path);
	else
		return ("./");
}

static void	ft_run_cmd(t_list **envhead, t_split *data)
{
	char	*name;
	int		status;
	pid_t	pid;

	pid = 0;
	status = 0;
	name = ft_file_exist(data->tokens[0], ft_getpath(envhead), 0);
	if (name)
	{
		pid = fork();
		if (!pid)
			ft_pipe_exec(name, envhead, data);
	}
	else
		ft_c_error(envhead, data->tokens[0], ": command not found", 127);
	waitpid(pid, &status, 0);
	if (status && name)
		ft_print_error(envhead, NULL, errno);
	else if (name)
		ft_print_error(envhead, NULL, 0);
	close_one_pipe(data);
	free(name);
}

static int	ft_builtin(t_split *data, t_list **envhead, t_list **lsthead)
{
	int len;
	int blt;

	len = ft_strlen(data->tokens[0]);
	blt = ft_checkbuilt(data, len);
	if (blt)
		return (built_exec(data, head, len, lsthead));
	else if (!blt && len)
		ft_run_cmd(envhead, data);
	return (0);
}

int	ft_execute(t_list **envhead, t_list **lsthead)
{
	t_split	*content;
	int		err;

	err = 0;
	ft_sigblock();
	if (!envhead || !lsthead)
		return (0);
	if (ft_lstsize(*lsthead) > 1)
		err = err | ft_initpipes(lsthead);//02.03 여까지함.
	while (*lsthead && err >= 0)
	{
		content = (t_split *)((*lsthead)->content);
		err = ft_redirect(envhead, content);
		if (!err)
			err = err | ft_builtin(content, envhead, lsthead);
		err = err | ft_close_redirect(content);
		ft_delone_entry(lsthead);
	}
	return (err);
}
