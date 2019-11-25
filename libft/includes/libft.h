/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaineka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:58:27 by hlaineka          #+#    #+#             */
/*   Updated: 2019/10/30 14:04:48 by hlaineka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define T_INT_MAX 2147483647
# define T_INT_MIN -2147483648
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;

}					t_list;

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
size_t				ft_strlen(char const *s);
char				*ft_itoa(int n);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
void				*ft_memset(void *ptr, int value, size_t num);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t num);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t num);
int					ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
char				*ft_strncpy(char *dest, const char *src, size_t num);
char				*ft_strcat(char *dest, const char *src);
void				*ft_memchr(const void *ptr, int c, size_t num);
char				*ft_strncat(char *dest, const char *src, size_t num);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *src, int c);
char				*ft_strrchr(const char *src, int c);
char				*ft_strstr(const char *str1, const char *str2);
char				*ft_strnstr(const char *str1, const char *str2, size_t n);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strncmp(const char *str1, const char *str2, size_t num);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int arg);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
int					ft_is_whitespace(const char c);
int					ft_define_length(int n);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
char				**ft_addstr(char **dest, char *src);
t_list				*ft_lstnew(const void *content, size_t content_size);
void  				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void  				ft_lstdel(t_list **alst, void (*del)(void *,size_t));
void  				ft_lstadd(t_list **alst, t_list *new);
void  				ft_lstiter(t_list *lst, void (*f)(t_list*elem));
t_list *  			ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
