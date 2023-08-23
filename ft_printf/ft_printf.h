/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseelaen <rseelaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:15:02 by rseelaen          #+#    #+#             */
/*   Updated: 2023/06/13 18:02:08 by rseelaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

//HEX KEYS
# define HEX_CAPS	"0123456789ABCDEF"
# define HEX_LOW	"0123456789abcdef"

//FLAGS
# define HEX_FLAG 	0b1
# define SPACE_FLAG 0b10
# define PLUS_FLAG 	0b100

//ft_printf.c
int		ft_printf(const char *s, ...);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		flag_handler(const char *str, va_list args, int len,
			unsigned char flags);

//num_printers.c
int		ft_putunsigned(unsigned int n);
int		ft_putnbr(int n);
int		ft_puthex(unsigned int n, int caps);
int		ft_putpointer(unsigned long int n, int flag);

//handlers.c
int		plus_handler(va_list args, int len);
int		space_handler(va_list args, int len);
int		hashtag_handler(const char c, va_list args, int len);

//checkers.c
int		format_checker(int len, va_list args, const char *str);
int		is_flag(char c);
int		flag_setter(unsigned char flags, char c);
int		is_placeholder(char c);

#endif