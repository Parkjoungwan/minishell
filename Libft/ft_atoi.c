/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:53:55 by joupark           #+#    #+#             */
/*   Updated: 2021/01/01 10:09:52 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_space(char c)
{
	if (c == '\t' || c == '\r' || c == '\n' ||
			c == ' ' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	int				pm;
	unsigned long	result;

	pm = 1;
	result = 0;
	while (ft_space(*str))
		str++;
	if (*str == '-')
	{
		pm = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	if (result >= 9223372036854775808ULL)
		return (pm == 1 ? -1 : 0);
	return (result * pm);
}
