/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchieko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:56:11 by cchieko           #+#    #+#             */
/*   Updated: 2020/01/14 14:59:24 by cchieko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stdarg.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <sys/types.h>

# define GNL_BUFF_SIZE 4096
# define BOLD_CYAN "\x1B[1m\033[36m"
# define RESET "\x1B[0m"
# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct		s_dlst
{
    void			*data;
    size_t			data_size;
    struct s_dlst	*next;
    struct s_dlst	*prev;
}					t_dlst;

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
int					ft_lstlen(t_list *list);
int					ft_intlen(int number);
void				ft_lstappend(t_list **alst, t_list *new);
long long			ft_abs(long long number);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int		            ft_isnumber(char *s);
int					ft_max(int n1, int n2);
void				ft_swap(void *data1, void *data2, size_t size);
char				*ft_itoa(int n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_free_array(char **arr);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_w(int number, int width);
void				ft_putnbr(int n);
void	            ft_putnbr_endl(int n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_w(char *str, int width, int left_aligned);
void                ft_puttab(char **tab);
void                ft_strappend(char **source, const char *addition);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strccpy(char *dst, const char *src, char c);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
char 				*ft_strcdup(const char *src, char c);
char 				*ft_strndup(const char *src, size_t len);
int					ft_strequ(char const *s1, char const *s2);
void	            ft_strmerge(char **origin, char *add);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char	            *ft_strjoin3(char *s1, char *s2, char *s3);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char                **ft_strsplit_wd(char const *string);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					get_next_line(const int fd, char **line);
void	            ft_error_msg(char *error);
void	            ft_free_string_tab(char ***);
int		            ft_str_isdigit(char *str);
char	            *ft_strnjoin(char *s1, int n, ...);
int	                ft_putchar_termcaps(int c);
char	            *ft_strjoin_free(char *s1, char *s2, int choice);
void	            ft_dlstadd(t_dlst **alst, t_dlst *new);
t_dlst		        *ft_dlstnew(void const *data, size_t data_size);
void	            ft_dlstdel(t_dlst **elem, void (*del)(void *, size_t));
void				ft_freetab(char ***tab);
char				**ft_addtotab(char **tab, char *add);
char				**ft_tabdup(char **tab);
char	            **ft_supprtotab(char **tab, int suppr);
int					ft_tablen(char **tab);
void				ft_exit(char *error, int status);
void				ft_putstr1(char const *str);
int					ft_intputchar(int c);
int                 ft_print_array(char **array);
char	            *ft_charappend(char *str, char c);
#endif
