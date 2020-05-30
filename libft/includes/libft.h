/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:37:22 by sfranc            #+#    #+#             */
/*   Updated: 2020/02/21 16:34:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** Librairies jointes : unistd.h pour write, stdlib.h pour malloc et free,
** string pour NULL et size_t.
*/
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include "get_next_line.h"
# include "color.h"

typedef enum				e_ex_ret
{
	SUCCESS = EXIT_SUCCESS,
	FAILURE = EXIT_FAILURE
}							t_ex_ret;

typedef enum				e_bool
{
	TRUE = 1,
	FALSE = 0
}							t_bool;

/*
** MEMORY MANAGEMENT
*/
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void	*dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);

/*
** CHAR
*/
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_isspace(int c);
char			ft_upcase(char c);

/*
** STRING
*/
void			ft_charswap(char **a, char **b);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnew_set(size_t size, char c);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void(*f)(char*));
void			ft_striteri(char *s, void(*f)(unsigned int, char*));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin3(char *s1, char *s2, char *s3);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
int				ft_nb_words(char const *s, char c);
int				ft_isnumber(char *s);
char			*ft_charappend(char *str, char c);
void			ft_strmerge(char **origin, char *add);
/*
** ARRAY OF STRING
*/
char			**ft_tabdup(char **array);
void			ft_puttab(char **array);
void			ft_freetab(char ***array);
int				ft_tablen(char **array);
char			**ft_addtotab(char **array, char *add);
char			**ft_supprtotab(char **array, int suppr);

/*
** DISPLAY
*/
void			ft_putchar(char c);
int				ft_intputchar(int c);
void			ft_putstr(char const *str);
void			ft_putendl(char const *str);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *str, int fd);
void			ft_putendl_fd(char const *str, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr_endl(int n);
void			printbit(int nb);
void			ft_puthexa(unsigned long long n);
void			ft_puthexa_uint64(uint64_t nbr);
void			ft_puthexa_uint32(uint32_t nbr);

/*
** LISTS
*/
typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void(*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstadd_last(t_list **alst, t_list *new);
int				ft_lstlen(t_list *list);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstprint(t_list *list);

/*
** CONVERSION NUMBERS <=> STRINGS
*/
int				ft_atoi(const char *str);
int				ft_atoi_base(char *str, int base);
char			*ft_itoa(int n);
char			*ft_itoa_base(int value, int base);
char			*ull_toa(unsigned long long nb);

/*
** NUMBERS
*/
int				*ft_range(int min, int max);
int				ft_intsize(int n);
void			sort_int_tab(int *array, unsigned int size);
int				ull_len(unsigned long long nb);
int				ft_abs(int nb);
uint32_t		ft_swap_uint32(uint32_t n);
uint64_t		ft_swap_uint64(uint64_t n);
unsigned short	ft_swap_short(unsigned short n);

/*
** ERROR HANDLING
*/
void			ft_exit(char *error, int status);

#endif
