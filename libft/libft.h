/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:05:47 by rseelaen          #+#    #+#             */
/*   Updated: 2023/08/06 19:50:19 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# define FD_MAX 1024
# define HEX_CAPS	"0123456789ABCDEF"
# define HEX_LOW	"0123456789abcdef"

//GNL
typedef struct s_Struct
{
	char	*buffer;
	size_t	len_b;
	size_t	cap_b;
}	t_List;

char	*lst_find(t_List *lst, char number);
int		lst_expand(t_List *lst);
char	*lst_getslice(t_List *lst, size_t start, size_t end);
// void	*ft_memmove(void *dest, const void *src, size_t n);
char	*get_next_line(int fd);

// Char functions
int		ft_toupper(int a);
int		ft_tolower(int a);
int		ft_isprint(int a);
int		ft_isascii(int a);
int		ft_isdigit(int a);
int		ft_isalpha(int a);
int		ft_isalnum(int a);

// String functions
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

// Memory functions
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
void	*ft_memchr(const void *str, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *ptr, int c, size_t num);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

// Convertion functions
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

// Print functions
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// Misc functions
int		ft_abs(int x);
void	ft_swap(int *a, int *b);

//BONUS PART
// Struct declaration
typedef struct s_list
{
	int				*content;
	struct s_list	*next;
}	t_list;

// Bonus functions
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));

#endif