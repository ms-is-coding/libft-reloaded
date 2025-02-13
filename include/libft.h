/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 23:32:58 by smamalig          #+#    #+#             */
/*   Updated: 2025/02/13 20:03:11 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

bool		ft_isalpha(unsigned char c);
bool		ft_isalnum(unsigned char c);
bool		ft_isdigit(unsigned char c);
bool		ft_isascii(unsigned char c);
bool		ft_isprint(unsigned char c);
bool		ft_iscntrl(unsigned char c);
bool		ft_isgraph(unsigned char c);
bool		ft_islower(unsigned char c);
bool		ft_ispunct(unsigned char c);
bool		ft_isspace(unsigned char c);
bool		ft_isupper(unsigned char c);
bool		ft_isxdigit(unsigned char c);
bool		ft_isblank(unsigned char c);

int			ft_toupper(int c);
int			ft_tolower(int c);

int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_mempcpy(void *dst, const void *src, size_t n);

char		*ft_stpcpy(char *dst, const char *src);
char		*ft_stpncpy(char *dst, const char *src, size_t n);

size_t		ft_strlen(const char *s);
size_t		ft_strnlen(const char *s, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strcoll(const char *s1, const char *s2);
int			ft_strerror_r(int errnum, char *buf, size_t size);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncpy(char *dst, const char *src, size_t dsize);
char		*ft_strcat(char *dst, const char *src);
char		*ft_strncat(char *dst, const char *src, size_t ssize);
char		*ft_strdup(const char *s);
char		*ft_strndup(const char *s, size_t n);
char		*ft_strpbrk(const char *s, const char *accept);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strtok(char *str, const char *delim);
char		*ft_strtok_r(char *str, const char *delim, char **saveptr);
char		*ft_strerror(int errnum);
char		*ft_strsignal(int sig);
size_t		ft_strcspn(const char *s, const char *reject);
size_t		ft_strspn(const char *s, const char *accept);
size_t		ft_strxfrm(char *dst, const char *src, size_t n);

int			ft_atoi(const char *nptr);
long		ft_atol(const char *nptr);
long long	ft_atoll(const char *nptr);

void		ft_free(void *ptr);
void		*ft_malloc(size_t size);
void		*ft_calloc(size_t n, size_t size);
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);

size_t		ft_strlcpy(char *dst, const char *src, size_t dsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dsize);
char		*ft_strnstr(const char *haystack, const char *needle, size_t n);

char		*ft_substr(const char *s, size_t start, size_t size);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strtrim(const char *s, const char *trim);
char		**ft_split(const char *s, char delim);
char		*ft_itoa(int n);
char		*ft_strmapi(const char *s, char (*f)(size_t, char));
void		ft_striteri(char *s, void (*f)(size_t, char *));

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(const char *s, int fd);
void		ft_putendl_fd(const char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int			ft_list_size(t_list *list);
t_list		*ft_list_new(void *content);
t_list		*ft_list_last(t_list *list);
void		ft_list_pushfront(t_list **ptr, t_list *el);
void		ft_list_pushback(t_list **ptr, t_list *el);
void		ft_list_delete(t_list *el, void (*del)(void *));
void		ft_list_clear(t_list **ptr, void (*del)(void *));
void		ft_list_foreach(t_list list, void (*f)(void *));
t_list		*ft_list_map(t_list list, void *(*f)(void *), void (*del)(void *));

/***********************/
/* <stdio.h> functions */
/***********************/

int			printf(const char *fmt, ...);
int			dprintf(int fd, const char *fmt, ...);

#endif
