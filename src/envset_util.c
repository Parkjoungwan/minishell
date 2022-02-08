/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envset_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:33:37 by joupark           #+#    #+#             */
/*   Updated: 2022/02/06 12:58:01 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_isnewlst(t_list **envhead, char *name, char *val)
{
	t_env	*content;

	content = malloc(sizeof(t_env));
	if (!envhead || !name || !val || !content)
		return (1);
	content->name = ft_calloc(ft_strlen(name) + 1, sizeof(char));
	content->value = ft_calloc(ft_strlen(val) + 1, sizeof(char));
	if (!content->name || !content->value)
		return (1);
	content->name = ft_memcpy(content->name, name, ft_strlen(name));
	content->value = ft_memcpy(content->value, val, ft_strlen(val) + 1);
	ft_lstadd_back(envhead, ft_lstnew(content));
	return (0);
}

int		ft_putenv(t_list **envhead, char *name, char *val)
{
	t_env	*tmp;
	t_list	*iter;

	iter = *envhead;
	while (iter)
	{
		tmp = (t_env *)(iter->content);
		if (!ft_strncmp(tmp->name, name, ft_strlen(name) + 1))
			break;
		iter = iter->next;
	}
	if (iter)
	{
		free(tmp->value);
		tmp->value = ft_calloc(ft_strlen(val) + 1, sizeof(char));
		tmp->value = ft_memcpy(tmp->value, val, ft_strlen(val));
	}
	else
		return (ft_isnewlst(envhead, name, val));
	if (tmp->value)
		return (0);
	else
		return (1);
}

char	**ft_exportenv(t_list **envhead)
{
	t_env	*content;
	t_list	*lst;
	char	**arr;
	char	*help;
	int		i;

	i = 0;
	arr = ft_calloc(ft_getenvnbr(envhead + 1), sizeof(char *));
	if (!arr)
		return (NULL);
	lst = *envhead;
	while (lst)
	{
		content = (t_env *)(lst->content);
		help = ft_strjoin(content->name, "=");
		arr[i] = ft_strjoin(help, content->value);
		lst = lst->next;
		i++;
		free(help);
	}
	arr[i] = NULL;
	return (arr);
}
