/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delentry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:59:54 by joupark           #+#    #+#             */
/*   Updated: 2022/02/07 11:01:12 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell0"

void	ft_delcmd(void	*lst)
{
	t_split	*cmdinfo;
	int		i;

	i = 0;
	cmdinfo = (t_split *)(lst);
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

void	ft_delone_entry(t_list **head)
{
	t_list	**curr;
	t_list	next;

	curr = head;
	if (!(*curr))
		return ;
	next = (*curr)->next;
	ft_lstdelone(*curr, &ft_delcmd);
	*curr = next;
	curr = &(*curr)->next;
}
