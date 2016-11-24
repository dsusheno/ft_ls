/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_multi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:24:33 by dsusheno          #+#    #+#             */
/*   Updated: 2016/03/04 16:24:35 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_lib.h"

void	ft_multi_print(t_info **head, t_gen *flag, t_app ap)
{
	t_info	*tmp;
	t_info	*tmp_save;

	tmp_save = *head;
	while (*head)
	{
		ft_is_link(head);
		if (!(S_ISDIR((*head)->mode)) && (*head)->is_link != 1)
		{
			ft_print2((*head), NULL, flag);
			if (tmp && tmp->next)
				tmp->next = (*head)->next;
			ap.rep++;
		}
		else
			ap.dir++;
		tmp = *head;
		*head = (*head)->next;
	}
	(*head) = tmp_save;
	if (ap.dir && ap.rep && flag->rr != 1)
		ft_putchar('\n');
	else if (ap.rep && *head && (*head)->next && (*head)->next->next)
		ft_putchar('\n');
}

void	ft_merge_multi(t_info **head, t_gen *flag)
{
	t_info *tmp;

	if (flag->f != 1)
	{
		ft_mergesort(head, flag->r, 0);
		if (flag->t == 1)
			ft_mergesort(head, flag->r, 1);
	}
	ft_sort_existe(head);
	while (*head && (*head)->no_existe == 1)
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd((*head)->name, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd((*head)->errmsg, 2);
		ft_putchar_fd('\n', 2);
		tmp = *head;
		*head = (*head)->next;
		free(tmp->name);
		free(tmp);
	}
}
