/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:07:38 by joupark           #+#    #+#             */
/*   Updated: 2022/01/12 11:08:59 by joupark          ###   ########.fr       */
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
# include <errno.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct s_env
{
	char	*name;
	char	*val;
}		t_env;

typedef struct s_split
{
	char	**tokens;
	char	*iname;
	char	*oname;
	int		err;
	int		redi;
	int		redo;
	int		appi;
	int		appo;
	int		fdout;
	int		fdin;
	int		fdhere;
	int		pcpyin;
	int		pcpyout;
	int		piped;
	int		pipenbr;
	int		*pipefd;
}		t_split;


char	*ft_strjoin(char const *s1, char const *s2);
char    *ft_strdup(const char *s);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strchr(const char *src, int c);
int     ft_isalnum(int ch);
char    *ft_strtrim(char const *s1, char const *set);
//01.12
void    *ft_memset(void *dst, int c, size_t lenght);
t_list  *ft_lstlast(t_list *lst);
void    *ft_calloc(size_t count, size_t size);
void    ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t  ft_strlcat(char *dest, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_envset(t_list **envhead, char **envs);
char    *ft_getenv(t_list *envhead, char *target);
char    *ft_make_prompt(t_list *envhead);
void    ft_sigdefine(void);
void    ft_delentry(void *lst);
void    ft_delcmd(void *lst);
void    ft_lstfree(t_list **env, int flag);
void    ft_exit(t_list **env, t_list ** lst);
#endif
