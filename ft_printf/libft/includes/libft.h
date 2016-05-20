/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:42:19 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/19 16:29:35 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 4096
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

char			**ft_2dtab(size_t i, size_t j);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
int				clean_open(const char *path, int flag);
int				clean_read(int fildes, char *buf, size_t nbyte);
int				ft_countwords(const char *s, char c);
intmax_t		ft_intmaxatoi(const char *str);
intmax_t		ft_intmaxuatoi(const unsigned char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isprime(int nb);
char			*ft_itoa(int n);
char			*ft_itoa_base(intmax_t n, size_t base);
char			*ft_itoa_baseuint(uintmax_t n, int base);
void			ft_foreach(int *tab, size_t length, void (*f)(int));
int				get_next_line(int const fd, char **line);
int				ft_lenwords(const char *s, char c, int word);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void(*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_sort_int_tab(int *tab, unsigned int size);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
void			ft_strclr(char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
void			ft_strdel(char **as);
char			*ft_strdup(const char *s1);
int				ft_strequ(char const *s1, char const *s2);
char			*ft_stringupper(char *str);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_and_free(char *s1, char *s2, int n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *s1, const char *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
char			*ft_strrchr(const char *s, int c);
void			*ft_strrev(char *str);
char			**ft_strsplit(char const *s, char c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_uatoi(const unsigned char *str);
uintmax_t		ft_uintmaxuatoi(const unsigned char *str);
void			ft_uputchar(unsigned char c);
void			ft_uputstr(unsigned char *s);
unsigned char	*ft_ustrcat(unsigned char *s1, char *s2);
unsigned char	*ft_uustrcat(unsigned char *s1, unsigned char *s2);
void			ft_ustrdel(unsigned char **as);
unsigned char	*ft_ustrdup(unsigned char *s1);
unsigned char	*ft_ustrjoin_and_free(unsigned char *s1, char *s2, int n);
unsigned char	*ft_uustrjoin_and_free(unsigned char *s1, unsigned char *s2,
		int n);
size_t			ft_ustrlen(unsigned char *s);
unsigned char	*ft_ustrsub(unsigned char *s, unsigned int start, size_t len);
unsigned char	*ft_ustrnew(size_t size);
size_t			ft_wcharlen(const wchar_t *wchar);
#endif
