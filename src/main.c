/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:10:43 by joupark           #+#    #+#             */
/*   Updated: 2021/12/17 17:02:57 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	ms_init_shell(t_list **head, t_list **lsthead, char *input, char *prt)
{
	while (1)
	{
		prt = ms_getprompt(*head);
		define_input_signals();
		input = readline(prt);
		if (!input)
		{
			free(prt);
			ms_exit(head, lsthead);
		}
		free(prt);
		if (!ft_strlen(input))
		{
			free(input);
			continue ;
		}
		add_history(input);
		scan_input(input, head, lsthead);
		if (!ms_read_arguments(lsthead, 0, 0))
			ms_execute(head, lsthead);
		else
			ms_c_error(head, "syntax ", " error", 2);
	}
}

void	ms_welcome(void)
{
	int		fd;
	char	*str;


	fd = open("src/.welcom.txt", O_RDONLY, 0600);
	str = NULL;
	if (fd < 0)
		return ;
	while (get_next_line(fd, &str) > 0)
	{
		printf("%s\n", str);
		free(str);
	}
	if (str)
		free(str);
	close (fd);
	return ;
}

int main(void)
{
	t_list	**ehead;
	t_list **lsthead;
	extern char	**environ;

	ehead = malloc(sizeof(t_list *));
	lsthead = malloc(sizeof(t_list *));
	if (!lstead || !ehead)
		return (1);
	*ehead = NULL;
	*lsthead = NULL;
	ms_welcome();
	ms_init_env(ehead, environ);
	ms_putenv(ehead, "?", "0");
	ms_init_shell(ehead, lsthead, NULL, NULL);
	return (0);
}
