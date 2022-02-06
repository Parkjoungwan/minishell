/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:52:07 by joupark           #+#    #+#             */
/*   Updated: 2022/02/05 11:01:59 by joupark          ###   ########.fr       */
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

void	ft_delentry(void *lst)
{
	t_env	*content;
	
	cnt = (t_env *)lst;
	if (content->name)
		free(content->name);
	if (content->value)
		free(content->value);
	free(content);
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

void		ft_builtin_unset(t_list **envhead, t_split *content)
{
	int	i;
	
	if (!content)
		return ;
	i = 1;
	while (ft_strlen(content->tokens[i]))
	{
		if (ft_isvalid(content->tokens[i]))
			ft_unsetvar(envhead, content->tokens[i]);
		else
		{
			printf("unset : \'%s\': not a valid", content->tokens[i]);
			printf(" identifier\n");
			ft_printf_error(envhead, NULL, 1);
			break;
		}
		i++;
	}
	return ;
}
