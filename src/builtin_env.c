/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:08:37 by joupark           #+#    #+#             */
/*   Updated: 2022/02/08 11:09:26 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	builtin_env(t_list **envhead)
{
	t_env	*ptr;
	t_list	*head;

	if (!envhead)
		return ;
	head = *envhead;
	while (head)
	{
		ptr = (t_env *)(head->content);
		printf("%s=", ptr->name);
		if (ptr->value)
			printf("%s\n", ptr->value);
		else
			printf("\n");
		head = head->next;
	}
	ms_print_error(envhead, NULL, 0);
	return ;
}
