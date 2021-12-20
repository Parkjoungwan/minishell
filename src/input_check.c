/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:07:01 by joupark           #+#    #+#             */
/*   Updated: 2021/12/20 13:29:27 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*cleanup(char *input)
{
	char	*help;

	help = ft_strtrim(input, "\t\r\n\v\f");
	if (!help)
		return (NULL);
	free(input);
	return (help);
}

void	scan_input(char *input, t_list **head, t_list **lsthead)
{
	char	**matrix;

	if (!input)
		return ;
	check_and_insert_spaces(&input);
	input = cleanup(input);
	if (!ft_strlen(input))
	{
		free(input);
		return ;
	}
	matrix = ms_cut_tokens(input, head);
	if (matrix)
		ms_populate_cmdlst(matrix, lsthead);
	free(input);
	free(matrix);
}
