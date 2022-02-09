/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 01:26:25 by joupark           #+#    #+#             */
/*   Updated: 2022/02/09 23:19:59 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_compare(char *one, char *two)
{
	int	i;

	i = 0;
	while (one && two)
	{
		if (one[i] > two[i])
			return (1);
		else if (one[i] < two[i])
			return (0);
		else if (one[i] == two[i])
			i++;
	}
	return (0);
}

static void	ft_bubble(t_env **lst, int nbr)
{
	t_env	*temp;
	int		swapped;
	int		run;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		run = 0;
		while (run < nbr - 1)
		{
			if (ft_compare(lst[run]->name, lst[run + 1]->name))
			{
				temp = lst[run];
				lst[run] = lst[run + 1];
				lst[run + 1] = temp;
				swapped = 1;
			}
			run++;
		}
	}
}

t_env	**ft_envsort(t_list **envhead)
{
	t_list	*lst;
	t_env	**result;
	int		i;

	i = 0;
	result = ft_calloc(ft_getenvnbr(envhead) + 1, sizeof(t_env *));
	if (!result)
		return (NULL);
	lst = *envhead;
	while (lst)
	{
		result[i] = (t_env *)(lst->content);
		i++;
		lst = lst->next;
	}
	result[i] = NULL;
	ft_bubble(result, ft_getenvnbr(envhead));
	return (result);
}
