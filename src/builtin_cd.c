/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:46:41 by joupark           #+#    #+#             */
/*   Updated: 2022/02/09 23:32:03 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_update_dir(t_list **envhead)
{
	int		err;
	char	*new;

	err = 0;
	ft_print_error(envhead, NULL, 0);
	err = ft_putenv(envhead, "OLDPWD", ft_getenv(*envhead, "PWD"));
	if (err == 0)
	{
		new = getcwd(NULL, 0);
		err = ft_putenv(envhead, "PWD", new);
		free(new);
	}
	return (err);
}

char	*check_tilde(t_list **envhead, char *str)
{
	if (str[0] == '~')
		return (ft_strjoin(ft_getenv(*envhead, "HOME"), &str[1]));
	return (ft_strdup(str));
}

int	ft_builtin_cd(t_list **envhead, t_split *cmdinfo)
{
	int		err;
	char	*new;

	if (!envhead || !cmdinfo)
		return (1);
	if (1 > ft_strlen(cmdinfo->tokens[1]))
		err = chdir(ft_getenv(*envhead, "HOME"));
	else
	{
		new = check_tilde(envhead, cmdinfo->tokens[1]);
		err = chdir(new);
		if (new)
			free(new);
	}
	if (err == -1)
		ft_print_error(envhead, cmdinfo->tokens[1], -1);
	else
	{
		err = ft_update_dir(envhead);
		ft_print_error(envhead, NULL, 0);
	}
	return (err);
}
