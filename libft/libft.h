/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslotova <kslotova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 08:42:46 by kslotova          #+#    #+#             */
/*   Updated: 2021/12/20 11:12:46 by kslotova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
void	ft_putnbr(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);
int		ft_isprint(int c);
char	*ft_strcat(char *s1, const char *s2);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncat(char *s1, const char *s2, size_t n);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strncpy(char *dst, const char *src, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
char	*ft_strstr(const char *haystack, const char *needle);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_strclr(char *s);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
void	ft_strdel(char **as);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
void	ft_striter(char *s, void (*f)(char *c));
void	ft_striteri(char *s, void (*f)(unsigned int n, char *c));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnew(size_t size);
char	**ft_strsplit(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
int		ft_strequ(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
t_list	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_bzero(void *s, size_t n);
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char	*ft_strcapital(char *str);
t_list	*ft_create_node(void *content);
void	ft_lstback(t_list **begin_list, void *data);
void	ft_swap(int *a, int *b);
int		ft_lstsize(t_list *begin_list);

#endif
