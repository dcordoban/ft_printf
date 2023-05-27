/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:57:20 by david             #+#    #+#             */
/*   Updated: 2023/05/25 22:18:08 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




static void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_printc('-');
		ft_printc('2');
		ft_putnbr(147483648);
		return ;
	}
	if (n < 0)
	{
		ft_printc('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	if (n < 10)
		ft_printc('0' + n);
}

int	ft_printnb(int nb)
{
	int	res;

	res = 0;

}
