/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joupark <joupark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:31:30 by joupark           #+#    #+#             */
/*   Updated: 2021/01/04 14:31:34 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include "libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char				*ft_strnstr(const char *s1, const char *s2, size_t len);
int					ft_isdigit(int c);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_putstr_fd(char *str, int fd);
t_list				*ft_lstnew(void *content);
size_t				ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
t_list				*ft_lstlast(t_list *lst);
int					ft_memcmp(const void *b1, const void *b2, size_t len);
void				ft_putnbr_fd(int nb, int fd);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
char				*ft_strchr(const char *src, int c);
void				ft_bzero(void *s, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_isascii(int c);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
int					ft_isprint(int c);
void				ft_putendl_fd(char const *s, int fd);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
		void (*del)(void *));
int					ft_lstsize(t_list *lst);
int					ft_toupper(int c);
char				**ft_split(char const *s, char c);
void				ft_lstadd_front(t_list **lst, t_list *new);
char				*ft_strrchr(const char *s, int c);
int					ft_isalpha(int n);
void				*ft_memchr(const void *b, int c, size_t len);
void				ft_putchar_fd(char c, int fd);
void				*ft_memset(void *dst, int c, size_t lenght);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_start(const char *s1, const char *set);
int					ft_end(const char *s1, const char *set);
char				*ft_strtrim(char const *s1, char const *set);
void				*ft_memmove(void *dst, const void *src, size_t len);
size_t				ft_strlcat(char *dest, const char *src, size_t dstsize);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s);
int					ft_space(char c);
int					ft_atoi(char *str);
int					ft_isalnum(int ch);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
char				*ft_itoa(int n);
int					ft_tolower(int c);

#endif
