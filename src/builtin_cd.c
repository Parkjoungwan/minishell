/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:46:41 by joupark           #+#    #+#             */
/*   Updated: 2022/02/07 11:48:01 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
//ft_putenv 리턴값 바꿔치기했음 0, 새로만들었으면 1

int	ft_update_dir(t_list **envhead) 
{
	int	err;
	char	*new;

	err = 0;
	ft_print_error(envhead, NULL, 0); // 나중에 해석하기
	err = ft_putenv(envhead, "OLDPWD", ft_getenv(*envhead, "PWD"));
	if (err = 0) // 바꿔치기했다면
	{
		new = getcwd(NULL, 0) // 현재 작업 디렉
		err = ft_putenv(envhead, "PWD", new);
		free(new);
	}
	return (err);
}

char	*check_tilde(t_list **envhead, char *str)
{
	if (str[0] == '~') //원본코드는 strlen 중복, HOME이 없을 경우까지 고려
		return (ft_strjoin(ft_getenv(*head, "HOME"), str[1]));
	return (ft_strdup(str));
}

void	builtin_cd(t_list **envhead, t_split *cmdinfo)
{
	int	err;
	char	*new;
	
	if (!envhead || !cmdinfo)
		return ;
	if (1 > ft_strlen(cmdinfo->tokens[1]))
		err = chdir(ft_getenv(*envhead, "HOME"));
	else
	{
		new = check_tilde(envhead, cmdinfo->tokens[1]); // 물결표인지 확인
		err = chdir(new);
		if (new)
			free(new);
	}
	if (err == -1) // chdir의 리턴값은 정상일 때 0, 에러시 -1
		ft_print_error(envhead, cmdinfo->tokens[1], -1);
	else
	{
		err = ft_update_dir(envhead);
		ft_print_error(envhead, NULL, 0);
	}
	return (err);
}
