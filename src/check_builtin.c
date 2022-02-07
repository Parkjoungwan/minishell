/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:11:17 by joupark           #+#    #+#             */
/*   Updated: 2022/02/07 11:00:09 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_checkbuilt(t_split *cmdinfo, int len)
{
	if (!len)
		return (0);
	else if (len > 3 && !strncmp(cmdinfo->tokens[0], "exit", len))
		return (1);
	else if (len > 1 && !strncmp(cmdinfo->tokens[0], "cd", len))
		return (1);
	else if (len > 2 && !strncmp(cmdinfo->tokens[0], "env", len))
		return (1);
	else if (len > 2 && !strncmp(cmdinfo->tokens[0], "pwd", len))
		return (1);
	else if (len > 3 && !strncmp(cmdinfo->tokens[0], "echo", len))
		return (1);
	else if (len > 4 && !strncmp(cmdinfo->tokens[0], "unset", len))
		return (1);
	else if (len > 5 && !strncmp(cmdinfo->tokens[0], "export", len))
		return (1);
	return (0);
}
