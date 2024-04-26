/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ryusupov.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:21:53 by ryusupov          #+#    #+#             */
/*   Updated: 2024/04/26 14:13:51 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RYUSUPOV_H
# define RYUSUPOV_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif
/*-----Text Style------*/
# define BOLD "\x1b[1m"
# define UNDERLINE "\x1b[4m"
# define ITALIC "\x1b[3m"
# define RESET "\x1b[0m"
/*-----Text Color-----*/
# define COLOR_RED "\x1b[31m"
# define COLOR_GREEN "\x1b[32m"
# define COLOR_YELLOW "\x1b[33m"
# define COLOR_BLUE "\x1b[24m"
# define COLOR_MAGENTA "\x1b[35m"
# define COLOR_CYAN "\x1b[36m"
# define COLOR_WHITE "\x1b[97m"
# define RESET "\x1b[0m"
/*-----Helper libs------*/
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/*-----------------lIST STRUCTS------------------*/

			/*------libft_struct--------*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

		/*-----get_next_line_struct------*/

typedef struct t_struct
{
	int				new_l_buffer;
	int				fd;
}					t_struct;

/*-----------------FT_PRINTF---------------------*/

int					ft_printf(const char *input, ...);
int					ft_putstr(char *c);
int					ft_putnbr(int c, int res);
int					ft_putchar(char s);
int					ft_print_adress(long *p);
int					ft_decimal(size_t i, int res);
int					ft_ishex(unsigned long long hex, int num, char uc);
// size_t				ft_strlen_printf(const char *str);

/*-----------------GET_NEXT_LINE------------------*/

t_struct			*get_t_struct(int new_fd);
char				*ft_strjoin_gnl(char *s1, char *s2);
char				*ft_strndup(char *str, int start, int end);
char				*get_next_line(int fd);
int					new_line(char *str);
size_t				ft_strlen(const char *str);

/*---------------LBFT FUNCTIONS------------------*/

void				*ft_realloc(void *ptr, size_t size);
void				ft_bzero(void *p, size_t n);
void				*ft_memcpy(void *to, const void *from, size_t n);
void				*ft_memset(void *p, int i, size_t len);
void				*ft_memmove(void *to, const void *from, size_t len);
void				*ft_memchr(const void *p, int i, size_t n);
void				ft_striteri(char *s1, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s1, int fd);
void				ft_putendl_fd(char *s1, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_calloc(size_t count, size_t size);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_isalnum(int i);
int					ft_isalpha(int i);
int					ft_isascii(int i);
int					ft_isdigit(int i);
int					ft_isprint(int i);
int					ft_toupper(int i);
int					ft_tolower(int i);
int					ft_lstsize(t_list *lst);
char				*ft_strtrim(char const *s1, char const *set);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s1, char (*f)(unsigned int, char));
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_split(char const *str, char set);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s1, unsigned int start, size_t len);
char				*ft_strnstr(const char *hydr, const char *needle, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int i);
char				*ft_strrchr(const char *p, int i);
size_t				ft_strlcpy(char *to, const char *from, size_t dstsize);
size_t				ft_strlcat(char *to, const char *from, size_t dstsize);
size_t				ft_strlen(const char *str);

/*-----------------BONUS PART-------------------*/

t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
int					ft_lstsize(t_list *lst);

#endif
