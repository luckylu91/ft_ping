/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:08:26 by lzins             #+#    #+#             */
/*   Updated: 2021/04/10 16:34:06 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_all_in(char *str, char *set);
void				**ft_array(size_t size1, size_t size2, size_t type_size);
void				ft_arrayclear(void **array, size_t size);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
char				*ft_strnstr(const char *hay, const char *needle, size_t n);
char				*ft_strskip(char const *s, char *delim, int skip_sep,
						size_t *flen);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char *delim);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new_element);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstfind(t_list *lst, void *content,
						size_t content_size);
void				ft_lstadd_back(t_list **alst, t_list *new_element);
int					ft_lstcpy(t_list *src, t_list **adest,
						size_t content_size);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
t_list				*ft_lstremove(t_list **alst, void *content,
						size_t content_size);
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstiter_arg(t_list *lst, void *arg,
									void (*f)(void *cont, void *arg));
void				ft_lstreviter(t_list *lst, void (*f)(void *));
void				ft_lstreviter_arg(t_list *lst, void *arg,
										void (*f)(void *cont, void *arg));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstcat(t_list *lst1, t_list *lst2);
int					ft_lstany(t_list *lst, int (*booleval)(void *content));
int					ft_lstany2(t_list *lst, void *ref,
								int (*booleval)(void *cont, void *ref));
t_list				*ft_lststep(t_list *lst, size_t n_steps);
t_list				*ft_lstskip(t_list *lst, int (*skip)(void *content));
int					ft_lstadd_back_content(t_list **alst, void *content);
int					ft_any(void *array, size_t len, size_t size,
							int (*booleval)(void*));
int					ft_strindex(const char *s, int c);
int					ft_intindex(const int *array, size_t n, int val);
int					ft_lstdup_back(t_list **alst, void *aval, size_t size);
int					ft_lstdupint_back(t_list **alst, int k);
char				*ft_lststrjoin(t_list *lst, char *sep, char *left,
									char *right);
size_t				ft_splitlen(char **splitted);
int					ft_isspace(int c);
int					ft_atoi_overflows(const char *str);
int					ft_lstindex(t_list *lst, void *content,
									size_t content_size);

#endif
