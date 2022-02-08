/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeprompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:22:36 by joupark           #+#    #+#             */
/*   Updated: 2022/01/18 11:31:22 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_getenv(t_list *envhead, char *target)
{
	t_env	*temp;

	if (!envhead || !target)
		return (NULL);
	while (envhead)
	{
		temp = (t_env *)(envhead->content);
		if (!ft_strncmp(temp->name, target, ft_strlen(target) + 1))
			return (temp->value);
		envhead = envhead->next;
	}
	return (NULL);
}

char	*ft_make_prompt(t_list *envhead)
{
	char	*prompt;
	char	*name;
	char	*dir;

	name = ft_getenv(envhead, "LOGNAME");
	dir = ft_getenv(envhead, "PWD");
	prompt = ft_calloc(ft_strlen(name) + ft_strlen(dir) + 16, sizeof(char));
	ft_strlcat(prompt, name, ft_strlen(name) + 1);
	ft_strlcat(prompt, ":\033[1;34m", ft_strlen(prompt) + 9);
	ft_strlcat(prompt, dir, ft_strlen(prompt) + ft_strlen(dir) + 1);
	ft_strlcat(prompt, "\x1b[0m$ ", ft_strlen(prompt) + 8);
	return (prompt);
}
