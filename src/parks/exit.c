/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:28:37 by joupark           #+#    #+#             */
/*   Updated: 2022/02/07 11:02:10 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_delentry(void *lst)
{
	t_env	*cnt;

	cnt = (t_env *)(lst);
	if (cnt->name)
		free(cnt->name);
	if (cnt->val)
		free(cnt->val);
	free(cnt);
}

void	ft_delcmd(void *lst)
{
	t_split	*cmdinfo;
	int		i;

	i = 0;
	cmdinfo = (t_split *)lst;
	if (!cmdinfo)
		return ;
	while (cmdinfo->tokens[i])
	{
		free(cmdinfo->tokens[i]);
		i++;
	}
	if (cmdinfo->tokens)
		free(cmdinfo->tokens);
	if (cmdinfo->iname)
		free(cmdinfo->iname);
	if (cmdinfo->oname)
		free(cmdinfo->oname);
	free(cmdinfo);
}

void	ft_lstfree(t_list **env, int flag)
{
	t_list	**curr;
	t_list	**next;

	curr = env;
	while (*curr)
	{
		next = (*curr)->next;
		if (!flag)
			ft_lstdelone(*curr, &ft_delentry);
		else
			ft_lstdelone(*curr, &ft_delcmd);
		*curr = next;
	}
	free(env);
}

void	ft_exit(t_list **env, t_list ** lst)
{
	int num;

	num = ft_atoi(ft_getenv(*env, "?"));
	if (env)
		ft_lstfree(env, 0);
	if (lst)
		ft_lstfree(lst, 1);
	exit(num);
}

void	ft_exit_cmd(t_list **envhead, t_list **lst, t_split *cmdinfo)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (cmdinfo->tokens[i])
	{
		if (ft_atoi(cmdinfo->tokens[i]))
			n++;
		i++;
	}
	if (n > 1)
	{
		printf("exit: too many arguments\n");
		ft_print_error(envhead, NULL, 1);
		return ;
	}
	if (i > 1)
		ft_print_error(envhead, NULL, ft_atoi(cmdinfo->tokens[1]));
	ft_exit(envhead, lst);
}
