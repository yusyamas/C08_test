/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:49:16 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/24 16:02:42 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <unistd.h>
#define FT_NULL '\0'

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != FT_NULL)
	{
		ft_putchar(*str);
		str += 1;
	}
	ft_putchar('\n');
}

void	ft_print_digit(int n)
{
	int	next_nbr;
	int	current_digit;

	if (n == 0)
		return ;
	next_nbr = n / 10;
	current_digit = n % 10;
	ft_print_digit(next_nbr);
	ft_putchar((char)('0' + current_digit));
	return ;
}

void	ft_show_tab(struct s_stock_str *par)
{
	t_stock_str	*c;

	c = par;
	while (1)
	{
		ft_putstr(c->str);
		if (c->size == 0)
			ft_putchar('0');
		else
			ft_print_digit(c->size);
		ft_putchar('\n');
		ft_putstr(c->copy);
		if (c->size == 0)
			break ;
		c += 1;
	}
}
