/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:43:38 by dcordoba          #+#    #+#             */
/*   Updated: 2023/06/01 12:49:18 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<unistd.h>
# include<stdarg.h>
# include<stdio.h>
# include<stddef.h>
# include<stdlib.h>

int	ft_printf(char const *format, ...);
int	ft_print_char(char c);
int	ft_prints(char *c);
int	ft_print_u(unsigned int nb);
int	ft_printnb(int nb);
int	ft_print_hex(const char format, unsigned int nb);
#endif
