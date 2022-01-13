/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:14:24 by joupark           #+#    #+#             */
/*   Updated: 2022/01/13 14:20:06 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	ft_print_error(t_list )

int	ft_c_error(t_list **envhead, char *s1, char *s2, int nbr)
{
	char	*msg;

	msg = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!msg)
		return ;
	ft_strlcat(msg, s1, ft_strlen(s1) + 1);
	ft_strlcat(msg, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_putendl_fd(msg, STDERR_FILENO);
	free(msg);
	msg = ft_itoa(nbr);
	ft_putenv(envhead, "?", msg);
	free(msg);
}
