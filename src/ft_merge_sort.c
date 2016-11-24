/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:25:05 by dsusheno          #+#    #+#             */
/*   Updated: 2016/03/04 16:25:09 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_lib.h"

void	split_list(t_info *source, t_info **l1, t_info **l2)
{
	t_info *fast;
	t_info *slow;

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

void	ms_time2(t_info **l1, t_info **l2, t_info **result, int *x)
{
	if (x[1] == 1)
		if (((*l1)->st != (*l2)->st) ? 1 : (*l1)->nsec >= (*l2)->nsec)
		{
			(*result) = (*l1);
			(*result)->next = ms_time((*l1)->next, (*l2), x[0]);
		}
		else
		{
			(*result) = (*l2);
			(*result)->next = ms_time((*l1), (*l2)->next, x[0]);
		}
	else
	{
		if (((*l1)->st != (*l2)->st) ? 1 : (*l1)->nsec <= (*l2)->nsec)
		{
			(*result) = (*l1);
			(*result)->next = ms_time((*l1)->next, (*l2), x[0]);
		}
		else
		{
			(*result) = (*l2);
			(*result)->next = ms_time((*l1), (*l2)->next, x[0]);
		}
	}
}

t_info	*ms_time(t_info *l1, t_info *l2, int r)
{
	t_info	*result;
	int		x[2];

	x[0] = r;
	result = NULL;
	if (l1 == NULL)
		return (l2);
	else if (l2 == NULL)
		return (l1);
	if ((l1->st >= l2->st) && r == 0)
	{
		x[1] = 1;
		ms_time2(&l1, &l2, &result, x);
	}
	else if ((l1->st <= l2->st) && r == 1)
	{
		x[1] = 0;
		ms_time2(&l1, &l2, &result, x);
	}
	else
	{
		result = l2;
		result->next = ms_time(l1, l2->next, r);
	}
	return (result);
}

t_info	*ms_ascii(t_info *l1, t_info *l2, int r)
{
	t_info *result;

	result = NULL;
	if (l1 == NULL)
		return (l2);
	else if (l2 == NULL)
		return (l1);
	if ((ft_strcmp(l1->name, l2->name)) <= 0 && r == 0)
	{
		result = l1;
		result->next = ms_ascii(l1->next, l2, r);
	}
	else if ((ft_strcmp(l1->name, l2->name)) >= 0 && r == 1)
	{
		result = l1;
		result->next = ms_ascii(l1->next, l2, r);
	}
	else
	{
		result = l2;
		result->next = ms_ascii(l1, l2->next, r);
	}
	return (result);
}

void	ft_mergesort(t_info **headref, int r, int ift)
{
	t_info *head;
	t_info *l1;
	t_info *l2;

	head = *headref;
	if ((head == NULL) || (head->next == NULL))
		return ;
	split_list(head, &l1, &l2);
	ft_mergesort(&l1, r, ift);
	ft_mergesort(&l2, r, ift);
	if (ift == 0)
		*headref = ms_ascii(l1, l2, r);
	else
		*headref = ms_time(l1, l2, r);
}
