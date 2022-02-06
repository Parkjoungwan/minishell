/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delentry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:59:54 by joupark           #+#    #+#             */
/*   Updated: 2022/01/13 11:05:08 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell0"

void	ft_delcmd(void	*lst)
{
	t_split	*content;
	int		i;

	i = 0;
	content = (t_split *)(lst);
	if (!content)
		return ;
	while (content->tokens[i])
	{
		free(content->tokens[i]);
		i++;
	}
	if (content->tokens)
		free(content->tokens);
	if (content->iname)
		free(content->iname);
	if (content->oname)
		free(content->oname);
	free(content);
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
