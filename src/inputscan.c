/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputsacn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:12:25 by joupark           #+#    #+#             */
/*   Updated: 2022/01/12 10:22:34 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*cleanup(char *input)
{

	char	*result;

	result = ft_strtrim(input, " \t\r\n\v\f");
	if (!result)
		return (NULL);
	free (input);
	return (result);
}

void		ft_inputscan(char *input, t_list **envhead, t_list **lsthead)
{
	char	**matrix;
	
	if (!input)
		return ;
	ft_insertspace(&input);
	input = ft_cleanup(input);
	if (!ft_strlen(input))
	{
		free(input);
		return ;
	}
	matrix = ft_cutbytokens(input, envhead);
	if (matrix)
		ft_makecmdlst(matrix, lsthead);
	free (input);
	free (matrix);
	return ;
}
