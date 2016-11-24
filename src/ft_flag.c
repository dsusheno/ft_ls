/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:23:14 by dsusheno          #+#    #+#             */
/*   Updated: 2016/03/04 16:23:17 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_lib.h"

int		ft_flag2(char **av, t_gen *flag, int x)
{
	if (av[flag->i][x] == 'r')
		flag->r = 1;
	else if (av[flag->i][x] == 'a')
		flag->a = 1;
	else if (av[flag->i][x] == 't')
		flag->t = 1;
	else if (av[flag->i][x] == 'T')
		flag->tt = 1;
	else if (av[flag->i][x] == 'l')
		flag->l = 1;
	else if (av[flag->i][x] == 'R')
		flag->rr = 1;
	else if (av[flag->i][x] == 'f')
	{
		flag->f = 1;
		flag->a = 1;
	}
	else if (av[flag->i][x] == '1')
		flag->rr = flag->rr;
	else
	{
		flag->symb = av[flag->i][x];
		return (1);
	}
	return (0);
}

int		ft_flag(char **av, t_gen *f, int x)
{
	while (av[f->i])
	{
		if (av[f->i][0] != '-')
			return (0);
		if (av[f->i][1] == '\0')
			return (0);
		if (av[f->i][0] == '-' && av[f->i][1] == '-' && av[f->i][2] == '\0')
		{
			f->i++;
			f->n_argc--;
			return (0);
		}
		while (av[f->i][x])
		{
			if (ft_flag2(av, f, x))
				return (1);
			x++;
		}
		x = 1;
		f->i++;
		f->n_argc--;
	}
	return (0);
}
