/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:26:25 by david             #+#    #+#             */
/*   Updated: 2023/05/27 20:20:09 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include<unistd.h>
# include<stdarg.h>
# include<stdio.h>


int	ft_printf(char const *format, ...);
int	ft_check_format(const char *format, va_list args, int result);
int	ft_eval_format(va_list args, const char format);
int	ft_print_char(char c);
int	ft_prints(char *c);
int	ft_printnb(int nb);
#endif










