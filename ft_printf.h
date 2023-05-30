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
int	ft_printnb(int nb);
#endif