/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delentry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:59:54 by joupark           #+#    #+#             */
/*   Updated: 2022/02/08 12:43:56 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_delone_entry(t_list **head)
{
	t_list	**curr;
	t_list	*next;

	curr = head;
	if (!(*curr))
		return ;
	next = (*curr)->next;
	ft_lstdelone(*curr, &ft_delcmd);
	*curr = next;
	curr = &(*curr)->next;
}
