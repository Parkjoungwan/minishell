/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initpipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:22:54 by joupark           #+#    #+#             */
/*   Updated: 2022/02/07 10:41:02 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_pipecheck(int i, int *fd, int size)
{
	if (i < size - 1)
	{
		if (pipe(fd + i * 2) == -1)
			return (2);
	}
	return (0);
}

int			ft_initpipes(t_list **lsthead)
{
	int		size;
	int		i;
	int		*fd;
	t_split	*cmdinfo;
	t_list	*run;
	
	size = ft_lstsize(*lsthead);
	fd = ft_calloc((size - 1) * 2, sizeof(int));
	if (!fd)
		return (1);
	i = 0;
	run = *lsthead;
	while (i < size)
	{
		cmdinfo = (t_split *)(run->content);
		cmdinfo->piped = size - 1;
		cmdinfo->pipenbr = i;
		cmdinfo->pipefd = fd;
		if (ft_pipecheck(i, fd, size))
			return (2);
		i++;
		run = run->next;
	}
	return (0);
}
