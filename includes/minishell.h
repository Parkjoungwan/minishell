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

typedef struct	s_env
{
	char		*name;
	char		*value;
}				t_env;

typedef struct	s_split
{
	char		**tokens;
	char		*iname;
	char		*oname;
	int			err;
	int			onei;
	int			oneo;
	int			twoi;
	int			twoo;
	int			fdout;
	int			fdin;
	int			fdhere;
	int			pcpyin;
	int			pcpyout;
	int			piped;
	int			pipenbr;
	int			*pipefd;
}				t_split;

int				ft_argumentscheck(t_list **lsthead, int i, int size);
void			close_one_pipe(t_split *cmdinfo);
void			close_pipes(t_split *cmdinfo);
void			ft_pipe_exec(char *name, t_list **envhead, t_split *cmdinfo);
void			ft_doc_input(t_list **envhead, t_split *cmdinfo);
int				ft_checktoken_input(t_split *cmdinfo, int i);
int				ft_checktoken_output(t_split *cmdinfo, int i);
void			ft_builtin_echo(t_list **envhead, t_split *cmdinfo);
void			ft_export_err(t_list **envhead, char *token);
void			ft_builtin_export(t_list **envhead, t_split *cmdinfo);
t_env			**ft_envsort(t_list **envhead);
char			*ft_file_exists(char *name, char *path, int i);
int				ft_execute(t_list **envhead, t_list **lsthead);
void			ft_delentry(void *lst);
void			ft_delcmd(void *lst);
void			ft_lstfree(t_list **env, int flag);
void			ft_exit(t_list **env, t_list ** lst);
void			ft_exit_cmd(t_list **envhead, t_list **lst, t_split *cmdinfo);
void			ft_sigdefine(void);
void			ft_sigblock(void);
void			ft_builtin_unset(t_list **envhead, t_split *cmdinfo);
void			ft_builtin_pwd(t_list **envhead);
void			ft_builtin_env(t_list **envhead);
char			*ft_expandmake(char *str, char *insert, int entry, int exit);
int				ft_expandcheck(char **matrix, int i);
void			exp_var(char **matrix, int i, t_list **envhead);
void			ft_makecmdlst(char **matrix, t_list **lsthead);
void			interrupt_here_document(int signal);
char			**ft_cutbytokens(char *input, t_list **envhead);
int				ft_findexit(char *str);
int				ft_findentry(char *str);
void			ft_expand_env(char **matrix, t_list **envhead);
void			ft_inputscan(char *input, t_list **envhead, t_list **lsthead);
int				ft_print_error(t_list **envhead, const char *str, int nbr);
void			ft_c_error(t_list **envhead, char *s1, char *s2, int nbr);
int				ft_close_redirect(t_split *cmdinfo);
int				ft_redirect(t_list **envhead, t_split *cmdinfo);
int				ft_update_dir(t_list **envhead);
char			*check_tilde(t_list **envhead, char *str);
int				ft_builtin_cd(t_list **envhead, t_split *cmdinfo);
int				ft_built_exec(t_split *cmdinfo, t_list **envhead, int len, t_list **lsthead);
void			ft_insertspace(char **line);
void			ft_delone_entry(t_list **head);
int				ft_checkbuilt(t_split *cmdinfo, int len);
int				ft_isnewlst(t_list **envhead, char *name, char *val);
int				ft_putenv(t_list **envhead, char *name, char *val);
char			**ft_exportenv(t_list **envhead);
char			*ft_getenv(t_list *envhead, char *target);
char			*ft_make_prompt(t_list *envhead);
int				ft_initpipes(t_list **lsthead);
void			ft_exit_here(int fd, char *str);
int				ft_envnamelen(char *str);
char			**ft_envsplit(char *str);
int				ft_env_addlist(t_list **envhead, char *env);
int				ft_getenvnbr(t_list **envhead);
int				ft_envset(t_list **envhead, char **envs);

#endif
