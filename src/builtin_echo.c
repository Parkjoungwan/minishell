/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 00:43:51 by joupark           #+#    #+#             */
/*   Updated: 2022/02/05 00:57:30 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_check_echoflag(char *str)
{
	if (!str || *str != '-')
		return (0);
	str++;
	while (*str)
	{
		if (*str != 'n')
			return (0);
		str++;
	}
	return (1);
}

static int	ft_echo_print(char *str, int flag)
{
	if (!flag)
		write(STDOUT_FILENO, str, ft_strlen(str));
	else
	{
		write(STDOUT_FILENO, " ", 1);
		write(STDOUT_FILENO, str, ft_strlen(str));
	}
}

void		ft_builtin_echo(t_list **envehead, t_split *content)
{
	int i;
	int flag;

	i = 1;
	flag = 0;
	while(ft_check_echoflag(content->tokens[i]))
	{
		flag++;
		i++;
	}
	while (content->tokens[i])
	{
		if (ft_strlen(content->tokens[i]) != 0)
		{
			if ((!flag && i > 1) || (flag && i > flag + 1))
				ft_echo_print(content->tokens[i], 1);
			else
				ft_echo_print(content->tokens[i], 0);
		}
		i++;
	}
	if (!flag)
		printf("\n");
	ft_print_error(envhead, NULL, 0);
}
