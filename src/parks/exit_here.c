/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_here.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:40:13 by joupark           #+#    #+#             */
/*   Updated: 2022/02/06 13:41:26 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exit_here(int fd, char *str)
{
	printf("warning: here-document delimited by");
	printf(" end-of-file (wanted \'%s\'\n)", str);
	close(fd);
	exit(errno);
}
