/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:26:25 by david             #+#    #+#             */
/*   Updated: 2023/05/25 22:19:52 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include<unistd.h>
# include<stdarg.h>
# include<stdio.h>


int	ft_printf(char const *format, ...);
int	ft_check_format(char *format, va_list args, int *result);
int	ft_eval_format(va_list args, int *format, int f);
int	ft_print_char(char c);
#endif










