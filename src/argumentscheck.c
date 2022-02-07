/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argumentscheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:32:17 by joupark           #+#    #+#             */
/*   Updated: 2022/02/07 11:03:53 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell0"

static void	ft_sortting(char **tok, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		if (!tok[i])
		{
			j = i + 1;
			while (j < size)
			{
				if (tok[j])
				{
					tok[i] = ft_strdup(tok[j]);
					free(tok[j]);
					tok[j] = NULL;
					break ;
				}
				j++;
			}
		}
		i++;
	}
}

static void	ft_synerror(t_list **lsthead)
{
	t_list	**curr;
	t_list	*next;

	curr = lsthead;
	while (*curr)
	{
		next = (*curr)->next;
		ft_lstdelone(*curr, &ft_delcmd);
		*curr = next;
	}
	*lsthead = NULL;
	ft_delone_entry(lsthead);
}

static int	ft_getsize(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_argumentscheck(t_list **lsthead, int i, int size)
{
	t_list	*lst;
	t_split	*cmdinfo;

	lst = *lsthead;
	while (lst)
	{
		i = 0;
		cmdinfo = (t_split *)(lst->content);
		size = ft_getsize(cmdinfo->tokens);
		while (i < size && i >= 0)
		{
			i = ft_checktoken_input(cmdinfo, i);
			if (i >= 0)
				i = ft_checktoken_output(cmdinfo, i);
			i++;
		}
		ft_sortting(cmdinfo->tokens, size);
		if (i < 0)
		{
			ft_synerror(lsthead);
			return (666);
		}
		lst = lst->next;
	}
	return (0);
}
