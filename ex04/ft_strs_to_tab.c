/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:00:33 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/26 12:58:08 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>
#define FT_NULL '\0'

unsigned int	ft_strlen(char *str)
{
	unsigned int	length;
	char			*c;

	length = 0;
	c = str;
	while (*c != FT_NULL)
	{
		length += 1;
		c += 1;
	}
	return (length);
}

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	length;
	char			*d;
	char			*s;

	length = ft_strlen(src) + 1;
	d = dest;
	s = src;
	while (length > 0)
	{
		*d = *s;
		d += 1;
		s += 1;
		length -= 1;
	}
	return (dest);
}

struct s_stock_str	*ft_last_struct(struct s_stock_str *par)
{
	par->str = (char *)malloc(sizeof(char));
	if (par->str == NULL)
		return (NULL);
	ft_strcpy(par->str, "");
	return (par);
}

struct s_stock_str	*ft_nonlast_struct(struct s_stock_str *par, char *s)
{
	par->size = ft_strlen(s);
	par->str = (char *)malloc(sizeof(char) * (par->size + 1));
	if (par->str == NULL)
		return (NULL);
	par->copy = (char *)malloc(sizeof(char) * (par->size + 1));
	if (par->copy == NULL)
		return (NULL);
	ft_strcpy(par->str, s);
	ft_strcpy(par->copy, par->str);
	return (par);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*container;
	t_stock_str	*c;
	int			i;

	container = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	c = container;
	i = 0;
	while (i < ac + 1)
	{
		if (i == ac)
		{
			if (ft_last_struct(container) == NULL)
				return (NULL);
			break ;
		}
		else
		{
			if (ft_nonlast_struct(container, av[i]) == NULL)
				return (NULL);
		}
		container += 1;
		i += 1;
	}
	return (c);
}
