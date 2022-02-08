/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 00:58:06 by joupark           #+#    #+#             */
/*   Updated: 2022/02/07 11:44:44 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int ft_hasequal(char *str)
{
	if (str && ((ft_strlen(str) < 3) || !ft_isalpha(*str)))
		return (0);
	while (str && *str)
	{
		if (!ft_isalnum(*str) && *str != '=')
			return (0);
		if (*str == '=')
			return (1);
		str++;
	}
	return (0);
}

static void	ft_print_export(t_list **envhead)
{
	t_env	**ptr;
	int		i;
	
	i = 0;
	ptr = ft_envsort(envhead);
	while (ptr && ptr[i])
	{
		printf("declare -x ");
		printf("%s=\"", ptr[i]->name);
		if (ft_getenv(*envhead, ptr[i]->name))
			printf("%s\"\n", ft_getenv(*envhead, ptr[i]->name));
		else
			printf("\"\n");
		i++;
	}
	free(ptr);
}

static char	*ft_trimmer(char *old)
{
	char	*new;

	if (old[0] == '\"')
		new = ft_strtrim(old, "\"");
	else if (old[0] == '\'')
		new = ft_strtrim(old, "\'");
	else
		return(old);
	free(old);
	return (new);
}

void	ft_export_err(t_list **envhead, char *token)
{
	char	*front;

	front = ft_calloc(9 + ft_strlen(token) + 1, sizeof(char));
	if (!front)
		return ;
	ft_strlcpy(front, "export: \'", 10);
	ft_strlcat(front, token, 9 + ft_strlen(token) + 1);
	ft_c_error(envhead, front, "\' is not a valid identifier", 1);
	free(front);
}

int	ft_builtin_export(t_list **envhead, t_split *cmdinfo)
{
	char	**new;
	int		i;

	i = 1;
	ft_print_error(envhead, NULL, 0);
	while (ft_strlen(cmdinfo->tokens[i]))
	{
		if (ft_hasequal(cmdinfo->tokens[i]))
		{
			new = ft_envsplit(cmdinfo->tokens[i]);
			if (new[0] && new[1])
			{
				new[1] = ft_trimmer(new[1]);
				ft_putenv(envhead, new[0], new[1]);
				free(new[0]);
				free(new[1]);
				free(new);
			}
		}
		else
			ft_export_err(envhead, cmdinfo->tokens[i]);
		i++;
	}
	if (i == 1)
		ft_print_export(envhead);
}
