/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:22:48 by dsusheno          #+#    #+#             */
/*   Updated: 2016/03/04 16:22:51 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_lib.h"

int		ft_nb_app(t_gen *flag)
{
	t_info			*head;
	int				nb_app;

	nb_app = 0;
	head = flag->head;
	while (head)
	{
		nb_app++;
		head = head->next;
	}
	return (nb_app);
}

void	ft_read_br2(char *tab, t_gen *flag, t_info *head, t_app *ap)
{
	char	*for_stat;

	if (tab[0] == '/' && tab[1] == '\0')
		for_stat = ft_strjoin(tab, head->name);
	else if (*tab)
		for_stat = ft_strjoin_char(tab, head->name, '/');
	else
		for_stat = ft_strdup(head->name);
	if (S_ISDIR(head->mode))
	{
		ap->nb_app_n++;
		if (ap->nb_app_n > 1)
			ft_putchar('\n');
		if (ap->nb_app > 1 || (flag->n_argc > 2))
		{
			ft_putstr(for_stat);
			ft_putstr(":\n");
		}
		ft_br(for_stat, flag, ap);
	}
	free(for_stat);
	for_stat = NULL;
}

void	ft_read_br(char *tab, t_gen *flag, t_app *ap)
{
	t_info			*tmp;
	t_info			*head;

	head = flag->head;
	while (head)
	{
		tmp = head;
		if (((!ft_strcmp(head->name, "..") ||
			!ft_strcmp(head->name, ".")) && head->dot == 1) ||
			(ft_strcmp(head->name, "..") && ft_strcmp(head->name, ".")))
		{
			ft_read_br2(tab, flag, head, ap);
			head = head->next;
		}
		else
			head = head->next;
		if (tmp && tmp->name)
		{
			free(tmp->name);
			free(tmp);
		}
	}
}

void	ft_br(char *tab, t_gen *flag, t_app *ap)
{
	t_info				*head;
	static int			n;

	if (!*tab)
		tab[0] = '.';
	if ((flag->head = ft_tri(tab, flag)))
	{
		if (n == 0)
		{
			ap->nb_app = ft_nb_app(flag);
			n++;
		}
		head = flag->head;
		ft_read_br(tab, flag, ap);
	}
}
