/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/05/02 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

int			ft_putchar_len(char c);
int			ft_putstr_len(char *str);
int			ft_putnbr_len(int num);
int			ft_printf(const char *spec, ...);
int			ft_printf_spec(va_list args, const char spec);
int			ft_hexlen(unsigned int num);
void		ft_puthex(unsigned int num, const char spec);
int			ft_hex(unsigned int num, const char spec);
int			ft_ptrlen(unsigned long long ptr);
int			ft_putptr(unsigned long long ptr);
int			ft_pointer(unsigned long long ptr);
int			ft_unlen(unsigned int num);
char		*ft_utoa(unsigned int num);
int			ft_unsigned(unsigned int num);

#endif