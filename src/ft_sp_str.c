/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sp_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:25:55 by dsusheno          #+#    #+#             */
/*   Updated: 2016/03/04 16:25:57 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_lib.h"

void	ft_sp_nbr(int sp1, int nbr, int sp2)
{
	char	*str;

	str = ft_itoa(nbr);
	sp1 = sp1 - ft_strlen(str);
	while (sp1 > 0)
	{
		ft_putchar(' ');
		--sp1;
	}
	ft_putstr(str);
	while (sp2)
	{
		ft_putchar(' ');
		--sp2;
	}
	free(str);
}

void	ft_sp_str(int sp1, char *str, int sp2, int mod)
{
	if ((mod == 1 || mod == 3) && str)
		sp1 = sp1 - ft_strlen(str);
	while (sp1 > 0)
	{
		ft_putchar(' ');
		--sp1;
	}
	ft_putstr(str);
	if (mod == 2 || mod == 3)
		sp2 = sp2 - ft_strlen(str);
	while (sp2 > 0)
	{
		ft_putchar(' ');
		--sp2;
	}
}
