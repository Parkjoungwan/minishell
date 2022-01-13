/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:20:47 by joupark           #+#    #+#             */
/*   Updated: 2022/01/13 14:07:55 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_run_cmd(t_list **envhead, t_split *data)
{
	char	*name;
	int		status;
	pid_t	pid;

	pid = 0;
	status = 0;
	name = //ft_file_exist(data->tokens[0], ft_getpath(envhead, 0));
	if (name)
	{
		pid = fork();
		if (!pid)
			//ft_pipe_exec(name, envhead, data);
	}
}

static int	ft_builtin(t_split *data, t_list **envhead, t_list **lsthead)
{
	int len;
	int blt;

	len = ft_strlen(data->tokens[0]);
	blt = //ft_checkbuilt(data, len);
	if (blt)
		return (//built_exec(data, head, len, lsthead));
	else if (!blt && len)
		//ft_run_cmd(envhead, data);
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
		err = err | //ft_initpipes(lsthead);
	while (*lsthead && err >= 0)
	{
		content = (t_split *)((*lsthead)->content);
		err = //ft_redirect(envhead, content);
		if (!err)
			err = err | ft_builtin(content, envhead, lsthead);
		err = err | ft_close_redirect(content);
		ft_delone_entry(lsthead);
	}
	return (err);
}
