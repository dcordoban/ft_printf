/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:43:38 by dcordoba          #+#    #+#             */
/*   Updated: 2023/06/04 11:30:12 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<unistd.h>
# include<stdarg.h>
# include<stddef.h>
# include<stdlib.h>

int		ft_printf(char const *format, ...);
int		ft_print_char(char c);
int		ft_prints(char *c);
void	*ft_print_u(unsigned int nb, int *len);
void	*ft_printnb(int nb, int *len);
int		ft_print_hex(const char format, unsigned long int nb, int *len);
int		ft_print_p(void	*p, int *len);
#endif
