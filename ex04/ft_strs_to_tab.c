/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:00:33 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/25 00:11:13 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
#define FT_NULL '\0'

unsigned int	ft_strlen(char *str)
{
	unsigned int	length;

	length = 0;
	while (*str != FT_NULL)
	{
		length += 1;
		str += 1;
	}
	return (length);
}

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	length;

	length = ft_strlen(src) + 1;
	while (length > 0)
	{
		*dest = *src;
		dest += 1;
		src += 1;
		length -= 1;
	}
	return (dest);
}

struct s_stock_str	*ft_last_struct(struct s_stock_str *par)
{
	par->size = 0;
	par->str = (char *)malloc(sizeof(char));
	if (par->str == NULL)
		return (NULL);
	par->copy = (char *)malloc(sizeof(char));
	if (par->copy == NULL)
		return (NULL);
	ft_strcpy(par->str, "");
	ft_strcpy(par->copy, par->str);
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
