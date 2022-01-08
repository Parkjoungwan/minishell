/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:12:03 by joupark           #+#    #+#             */
/*   Updated: 2022/01/05 10:36:28 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*cur;
	t_list	*temp_next;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	result = ft_lstnew(f(lst->content));
	if (!result)
		return (NULL);
	cur = result;
	lst = lst->next;
	while (lst)
	{
		temp_next = ft_lstnew(f(lst->content));
		if (!temp_next)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		cur->next = temp_next;
		cur = temp_next;
		lst = lst->next;
	}
	return (result);
}
