/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:57:36 by joupark           #+#    #+#             */
/*   Updated: 2022/01/25 12:05:17 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_inputcon(t_list **envhaed, t_split *ptr)
{
	int	fd;

	fd = open(ptr->iname, O_RDONLY, 0644);
	if (fd == -1)
	{
		ft_print_error(envhead, ptr->iname, -1);
		return (1);
	}
	ptr->fdin = dup(STDIN_FILENO);
	if (dup2(fd, STDIN_FILENO) == -1)
		ft_printf_error(envhead, "dup2", -1);
	if (ptr->fdin == -1)
	{
		ft_print_error(envhead, "dup", -1);
		return (2);
	}
	return (0);
}

static int	ft_outputcon(t_list **envhead, t_split *ptr)
{
	int fd;

	fd = 0;
	if (ptr->redo == 1)
		fd = open(ptr->oname, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	else if (ptr->appo == 1)
		fd = open(ptr->oname, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		ft_print_error(envhead, ptr->oname, -1);
		return (1);
	}
	ptr->fdout = dup(STDOUT_FILENO);
	if (dup2(fd, STDOUT_FILENO) == -1)
		ft_print_error(envhead, "dup2", -1);
	if (ptr->fdout == -1)
	{
		ft_print_error(envhead, "dup", -1);
		return (2);
	}
	return (0);
}

int	ft_close_redirect(t_split *con)
{
	int err;

	err = 0;
	if (con->fdin > 0)
	{
		err = dup2(con->fdin, STDIN_FILENO);
		close(con->fdin);
	}
	if (con->fdout > 0)
	{
		err = err | dup2(con->fdout, STDIN_FILENO);
		close(con->fdout);
	}
	if (con->fdhere > 0)
	{
		err = err | dup2(con->fdhere, STDIN_FILENO);
		close(con->fdhere);
	}
	return (err);
}

int			ft_redirect(t_list **envhead, t_split *content)
{
	int	err;

	err = 0;
	if (content->redi)
		err = ft_inputcon(envhead, content);
	if (!err && content->appi)
		ft_doc_input(envhead, content);
	if (!err && (content->redo || content->appo))
		err = err | ft_outputcon(head, content);
	return (err);
}
