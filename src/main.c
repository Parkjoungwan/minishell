/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:07:15 by joupark           #+#    #+#             */
/*   Updated: 2022/01/12 14:29:27 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* 환경변수 체크완료 21.1.5
void	ft_envcheck(t_list **envhead)
{
	t_list *temp;

	temp = *envhead;
	while (temp)
	{
		printf("%s ", ((t_env *)temp->content)->name);
		printf("= %s\n", ((t_env *)temp->content)->val);
		temp = temp->next;
	}
}*/

void	ft_init_shell(t_list **envhead, t_list **lsthead, char *input, char *prom)
{
	while (1)
	{
		prom = ft_make_prompt(*envhead);
		ft_sigdefine();
		//input 체크완료 21.1.11
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
		//inputsacn 코드 작성 21.1.12
		if (!ft_argumentscheck(lsthead, 0, 0))
			ft_execute(envhead, lsthead);
		else
			ft_c_error(envhead, "syntax ", " error", 2);
	}
}

int	main(void)
{
	t_list	**envhead;
	t_list	**lsthead;
	extern	char	**environ;

	envhead = malloc(sizeof(t_list *));
	lsthead = malloc(sizeof(t_list *));
	if (!lsthead || !envhead)
		return (1);
	*envhead = NULL;
	*lsthead = NULL;
	if (ft_envset(envhead, environ))
		return (1);
	ft_init_shell(envhead, lsthead, NULL, NULL);
	//ft_envcheck(envhead);
	//환경변수 체크완료 21.1.5
	return (0);
}
