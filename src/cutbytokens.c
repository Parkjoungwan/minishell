/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cutbytokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:29:45 by joupark           #+#    #+#             */
/*   Updated: 2022/01/12 11:44:28 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*ft_skipspace(char *str)
{
	while (*str == 32 || (*str > 7 && *str < 14))
		str++;
	return (str);
}

static char *ft_findnext(char *str, char c)
{
	while (*str && *str != c)
		str++;
	if (*str)
		str++;
	return (str);
}

static char	*ft_cutting(char *init, char *end)
{
	char	*token;
	int		len;

	len = (int)(end - init);
	if (!len)
		return (NULL);
	token = ft_calloc(len + 1, sizeof(char));
	if (!token)
		return (token);
	token = memcpy(token, init, len);
	return (token);
}

static void	ft_fillmatrix(char **matrix, char *init, char *end, int i)
{
	while (matrix && end && *end)
	{
		if (*end == 32)
		{
			matrix[i] = ft_cutting(init, end);
			end = ft_skipspace(end);
			init = end;
			i++;
		}
		else if (*end == '"' || *end == '\'')
		{
			end = ft_findnext(end + 1, *end);
			matrix[i] = ft_cutting(init, end);
			end = ft_skipspace(end);
			init = end;
			i++;
		}
		else if (*end)
			end++;
	}
	matrix[i] = ft_cutting(init, end);
}

char	**ft_cutbytokens(char *input, t_list **envhead)
{
	char	**matrix;

	matrix = ft_calloc(ft_strlen(input) + 1, sizeof(char *));
	if (!matrix)
		return (NULL);
	ft_fillmatrix(matrix, input, input, 0);
	ft_expand_env(matrix, envhead);
	return (matrix);
}
