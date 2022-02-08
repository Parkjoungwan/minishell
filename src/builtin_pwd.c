/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:43:13 by joupark           #+#    #+#             */
/*   Updated: 2022/02/07 11:43:45 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_builtin_pwd(t_list **envhead)
{
	char	*str;

	str = ft_getenv(*envhead, "PWD");
	if (str)
		printf("%s\n", str);
	ft_print_error(envhead, NULL, 0);
}
