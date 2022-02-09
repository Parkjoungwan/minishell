/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:52:07 by joupark           #+#    #+#             */
/*   Updated: 2022/02/09 23:13:27 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_isvalid(char *str)
{
	while (str && *str)
	{
		if (!ft_isalnum(*str))
			return (0);
		str++;
	}
	return (1);
}

static int	ft_namecmp(t_list *lst, char *str)
{
	t_env	*tmp;

	tmp = (t_env *)lst->content;
	if (!ft_strncmp(str, tmp->name, ft_strlen(tmp->name) + 1))
		return (1);
	return (0);
}

static void	ft_unsetvar(t_list **envhead, char *str)
{
	t_list	**current;
	t_list	*next;
	int		i;

	i = 0;
	current = envhead;
	while (*current)
	{
		if (ft_namecmp(*current, str))
		{
			next = (*current)->next;
			ft_lstdelone(*current, &ft_delentry);
			*current = next;
			break ;
		}
		i++;
		current = &(*current)->next;
	}
}

void	ft_builtin_unset(t_list **envhead, t_split *cmdinfo)
{
	int	i;

	if (!cmdinfo)
		return ;
	i = 1;
	while (ft_strlen(cmdinfo->tokens[i]))
	{
		if (ft_isvalid(cmdinfo->tokens[i]))
			ft_unsetvar(envhead, cmdinfo->tokens[i]);
		else
		{
			printf("unset : \'%s\': not a valid", cmdinfo->tokens[i]);
			printf(" identifier\n");
			ft_print_error(envhead, NULL, 1);
			break ;
		}
		i++;
	}
	return ;
}
