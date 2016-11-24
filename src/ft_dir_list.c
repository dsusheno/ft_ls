/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:23:00 by dsusheno          #+#    #+#             */
/*   Updated: 2016/03/04 16:23:03 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_lib.h"

void	ft_dir_list(t_gen *flag, int *n_app)
{
	t_info	*head;
	int		dir;

	dir = 0;
	++(*n_app);
	head = flag->head;
	while (head)
	{
		if (S_ISDIR(head->mode) && ft_strcmp(head->name, "..")
			&& ft_strcmp(head->name, "."))
			dir++;
		head = head->next;
	}
	if (flag->rr == 1 && dir)
		ft_putchar('\n');
}
