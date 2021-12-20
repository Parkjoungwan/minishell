/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:59:12 by joupark           #+#    #+#             */
/*   Updated: 2021/12/20 13:00:26 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ms_exit(t_list **env, t_list **ctt)
{
	int nbr;

	nbr = ft_atoi(ms_getenv(*env, "?"));
	if (env)
		ms_free_env(env, 0);
	if (ctt)
		ms_free_env(ctt, 1);
	exit(nbr);
}
