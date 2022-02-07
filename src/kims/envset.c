/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:13:45 by joupark           #+#    #+#             */
/*   Updated: 2022/02/05 10:30:10 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_envnamelen(char *str)
{
	int i;

	i = 0;
	while (*str && *str != '=')
	{
		i++;
		str++;
	}
	return (i);
}

char	**ft_envsplit(char *str)
{
	char	**new;
	int		len;

	if (!str || !*str)
		return (NULL);
	len = ft_envnamelen(str);
	new = ft_calloc(2, sizeof(char *));
	if (!new)
		return (NULL);
	new[0] = ft_calloc(len + 1, sizeof(char));
	if (!new[0])
		return (NULL);
	new[0] = ft_memcpy(new[0], str, len);
	len = ft_strlen(str) - 1 - len;
	if (len)
		new[1] = ft_calloc(len + 1, sizeof(char));
	else
		new[1] = NULL;
	if (new[1])
		new[1] = ft_memcpy(new[1], str + ft_strlen(new[0]) + 1, len);
	return (new);
}

int	ft_env_addlist(t_list **envhead, char *env)
{
	t_env	*node;
	char	**split;

	node = malloc(sizeof(t_env));
	if (!node)
		return (1);
	split = ft_envsplit(env);
	if (!split)
		return (1);
	node->name = split[0];
	node->val = split[1];
	ft_lstadd_back(envhead, ft_lstnew(node));
	free(split);
	return (0);
}

int	ft_getenvnbr(t_list **envhead)
{
	int		i;
	t_list *tmp;

	tmp = *envhead;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_envset(t_list **envhead, char **envs)
{
	int err_check;
	int i;

	err_check = 0;
	i = 0;
	while (!err_check && envs && envs[i])
	{
		err_check = ft_env_addlist(envhead, envs[i]);
		i++;
	}
	if (!envs || !i)
		err_check = 1;
	return (err_check);
}
