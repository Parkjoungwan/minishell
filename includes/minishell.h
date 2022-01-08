/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:07:38 by joupark           #+#    #+#             */
/*   Updated: 2022/01/05 16:36:53 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../Libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <pthread.h>
# include <signal.h>

typedef struct s_env
{
	char	*name;
	char	*val;
}		t_env;

int    ft_envset(t_list **envhead, char **envs);
char    *ft_getenv(t_list *envhead, char *target);
char    *ft_make_prompt(t_list *envhead);
void    ft_sigdefine(void);
#endif
