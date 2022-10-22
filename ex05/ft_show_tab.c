/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:49:16 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/23 00:21:27 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strs_to_tab.h"
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

/*
void	ft_show_tab(struct s_stock_str *par)
{
	int			i;
	int			ac;
	t_stock_str	*c;

	i = 0;
	ac = (int)((sizeof par) / sizeof(struct s_stock_str));
	c = par;
	while (i < ac)
	{
		ft_putstr(c->str);
		ft_print_digit(c->size);
		ft_putchar('\n');
		ft_putstr(c->copy);
		c += 1;
		i += 1;
	}
}
*/

void	ft_show_tab(struct s_stock_str *par)
{
	t_stock_str	*c;

	c = par;
	while (1)
	{
		if (c->size == 0)
			break ;
		printf("%s\n", c->str);
		printf("%d\n", c->size);
		printf("%s\n", c->copy);
		c += 1;
	}
}
