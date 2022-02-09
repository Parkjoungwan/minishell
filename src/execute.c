/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:20:47 by joupark           #+#    #+#             */
/*   Updated: 2022/02/09 15:57:14 by joupark          ###   ########.fr       */
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

static void	ft_run_cmd(t_list **envhead, t_split *cmdinfo)
{
	char	*name;
	int		status;
	char	**envv;
	pid_t	pid;
	
	pid = 0;
	status = 0;
	name = ft_file_exists(cmdinfo->tokens[0], ft_getpath(envhead), 0);
	if (name)
	{
		pid = fork();
		if (!pid)
			ft_pipe_exec(name, envhead, cmdinfo);
	}
	else
		ft_c_error(envhead, cmdinfo->tokens[0], ": command not found", 127);
	waitpid(pid, &status, 0);
	if (status && name)
		ft_print_error(envhead, NULL, -1);
	else if (name)
		ft_print_error(envhead, NULL, 0);
	close_one_pipe(cmdinfo);
	free(name);
}

static int	ft_builtin(t_split *cmdinfo, t_list **envhead, t_list **lsthead)
{
	int len;
	int blt;

	len = ft_strlen(cmdinfo->tokens[0]);
	blt = ft_checkbuilt(cmdinfo, len);
	if (blt)
		return (ft_built_exec(cmdinfo, envhead, len, lsthead));
	else if (!blt && len)
		ft_run_cmd(envhead, cmdinfo);
	return (0);
}

static void	ft_fakeredirect(t_split *cmdinfo, int i)
{
	char *temp;

	while (cmdinfo->tokens[++i])
	{
		temp = cmdinfo->tokens[i];
		if (!ft_strncmp(cmdinfo->tokens[i], "<+-+", 4))
			temp = ft_strdup("<"); 
		else if (!ft_strncmp(cmdinfo->tokens[i], "<<+-+", 5))
			temp = ft_strdup("<<"); 
		else if (!ft_strncmp(cmdinfo->tokens[i], ">+-+", 4))
			temp = ft_strdup(">"); 
		else if (!ft_strncmp(cmdinfo->tokens[i], ">>+-+", 5))
			temp = ft_strdup(">>");
		if (temp != cmdinfo->tokens[i])
		{
			free(cmdinfo->tokens[i]);
			cmdinfo->tokens[i] = temp;
		}
	}
}

int	ft_execute(t_list **envhead, t_list **lsthead)
{
	t_split	*cmdinfo;
	int		err;

	err = 0;
	ft_sigblock();
	if (!envhead || !lsthead)
		return (0);
	if (ft_lstsize(*lsthead) > 1)
		err = err | ft_initpipes(lsthead);
	while (*lsthead && err >= 0)
	{
		cmdinfo = (t_split *)((*lsthead)->content);
		ft_fakeredirect(cmdinfo, -1);
		err = ft_redirect(envhead, cmdinfo);
		if (!err)
			err = err | ft_builtin(cmdinfo, envhead, lsthead);
		err = err | ft_close_redirect(cmdinfo);
		ft_delone_entry(lsthead);
	}
	return (err);
}
