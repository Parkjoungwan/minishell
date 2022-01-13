/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigdefine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:30:34 by joupark           #+#    #+#             */
/*   Updated: 2022/01/13 13:42:36 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	display_prompt(int num)
{
	(void)num;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	ft_sigdefine(void)
{
	signal(SIGINT, display_prompt);
	signal(SIGQUIT, SIG_IGN);
}

static void	display_block(int num)
{
	(void)num;
	write(1, "\n", 1);
}

static void	quit_process(int num)
{
	(void)num;
	printf("Quit (core dumped)\n");
}

void	ft_sigblock(void)
{
	signal(SIGINT, display_block);
	signal(SIGQUIT, quit_process);
}
