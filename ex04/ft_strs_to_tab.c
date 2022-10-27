/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:00:33 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/26 15:04:00 by yusyamas         ###   ########.fr       */
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

char	*ft_memcpy(char *dest, char *src, unsigned int len)
{
	char	*c;

	c = dest;
	while (len > 0)
	{
		*dest = *src;
		dest += 1;
		src += 1;
		len -= 1;
	}
	return (c);
}

char	*ft_strdup(char *src)
{
	char			*dupstr;
	unsigned int	srclen;

	srclen = ft_strlen(src);
	dupstr = (char *)malloc(sizeof(char) * (srclen + 1));
	ft_memcpy(dupstr, src, srclen + 1);
	return (dupstr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*container;
	int			i;

	container = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	i = 0;
	while (i < ac)
	{
		container[i].str = av[i];
		container[i].size = (int)ft_strlen(av[i]);
		container[i].copy = ft_strdup(av[i]);
		i += 1;
	}
	container[i].str = 0;
	return (container);
}
