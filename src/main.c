/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:07:15 by joupark           #+#    #+#             */
/*   Updated: 2022/02/08 12:54:42 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_init_shell(t_list **envhead, t_list **lsthead, char *input, char *prom)
{
	while (1)
	{
		prom = ft_make_prompt(*envhead);
		ft_sigdefine();
		input = readline(prom);
		if (!input)
		{
			free(prom);
			ft_exit(envhead, lsthead);
		}
		free(prom);
		if (!ft_strlen(input))
		{
			free(input);
			continue;
		}
		add_history(input);
		ft_inputscan(input, envhead, lsthead);
		if (!ft_argumentscheck(lsthead, 0, 0))
			ft_execute(envhead, lsthead);
		else
			ft_c_error(envhead, "syntax ", " error", 2);
	}
}

int	main(void)
{
	t_list		**envhead;
	t_list		**lsthead;
	extern char	**environ;

	envhead = malloc(sizeof(t_list *));
	lsthead = malloc(sizeof(t_list *));
	if (!lsthead || !envhead)
		return (1);
	*envhead = NULL;
	*lsthead = NULL;
	if (ft_envset(envhead, environ))
		return (1);
	ft_putenv(envhead, "?", "0");
	ft_init_shell(envhead, lsthead, NULL, NULL);
	return (0);
}
