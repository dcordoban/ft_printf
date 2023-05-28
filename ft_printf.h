/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:26:25 by david             #+#    #+#             */
/*   Updated: 2023/05/28 21:16:41 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<unistd.h>
# include<stdarg.h>
# include<stdio.h>
# include<stddef.h>

int	ft_printf(char const *format, ...);
int	ft_print_char(char c);
int	ft_prints(char *c);
int	ft_print_u(unsigned int nb);
#endif










