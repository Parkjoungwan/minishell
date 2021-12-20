/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:03:37 by joupark           #+#    #+#             */
/*   Updated: 2021/12/17 17:19:54 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ms_getprompt(t_list *head)
{
	char	*prompt;
	char	*name;
	char	*dir;

	name = ms_getenv(head, "LOGNAME");
	dir = ms_getenv(head, "PWD");
	prompt = calloc(ft_strlen(name) + ft_strlen(dir) + 16, sizeof(char));
	ft_strlcat(prompt, name, ft_strlen(name) + 1);
	ft_strlcat(prompt, ":\033[1;34m", ft_strlen(prompt) + 9);
	ft_strlcat(prompt, dir, ft_strlen(prmopt) + ft_strlen(dir) + 1);
	ft_strlcat(prompt, "\x1b[0m$ ", ft_strlen(prompt) + 8);
	return (prompt);
}

char	*ms_getenv(t_list *head, char *str)
{
	t_env	*val;

	if (!head || !str)
		return (NULL);
	while (head)
	{
		val = (t_env *)(head->content);
		if (!strncmp(val->name, str, ft_strlen(str) + 1))
			return (val->value);
		head = head->next;
	}
	return (NULL);
}
