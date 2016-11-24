/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:24:17 by dsusheno          #+#    #+#             */
/*   Updated: 2016/03/04 16:24:19 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_lib.h"

void	split_list_exist(t_info *source, t_info **l1, t_info **l2)
{
	t_info	*fast;
	t_info	*slow;

	if (source == NULL || source->next == NULL)
	{
		*l1 = source;
		*l2 = NULL;
	}
	else
	{
		slow = source;
		fast = source->next;
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*l1 = source;
		*l2 = slow->next;
		slow->next = NULL;
	}
}

t_info	*existe(t_info *l1, t_info *l2)
{
	t_info *result;

	result = NULL;
	if (l1 == NULL)
		return (l2);
	else if (l2 == NULL)
		return (l1);
	if (l1->no_existe >= l2->no_existe)
	{
		result = l1;
		result->next = existe(l1->next, l2);
	}
	else
	{
		result = l2;
		result->next = existe(l1, l2->next);
	}
	return (result);
}

void	ft_sort_existe(t_info **headref)
{
	t_info *head;
	t_info *l1;
	t_info *l2;

	head = *headref;
	if ((head == NULL) || (head->next == NULL))
		return ;
	split_list_exist(head, &l1, &l2);
	ft_sort_existe(&l1);
	ft_sort_existe(&l2);
	*headref = existe(l1, l2);
}
