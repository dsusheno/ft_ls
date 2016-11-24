/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:26:47 by dsusheno          #+#    #+#             */
/*   Updated: 2016/03/04 16:26:50 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_lib.h"

void	ft_init_list(t_info *info)
{
	info->no_existe = 0;
	info->st = 0;
	info->errmsg = NULL;
	info->name = NULL;
	info->dot = 0;
}

void	ft_is_link(t_info **head)
{
	struct stat		st;
	char			buf[1025];
	size_t			len;

	if (S_ISLNK((*head)->mode))
	{
		len = readlink((*head)->name, buf, 1024);
		buf[len] = '\0';
		lstat(buf, &st);
		if (S_ISDIR(st.st_mode))
			(*head)->is_link = 1;
	}
}

void	creat_list_multi_back(char **av, t_info *info, int i, t_gen *flag)
{
	struct stat	stat;

	info->name = ft_strdup(av[i]);
	if (!ft_strcmp(info->name, "..") ||
		!ft_strcmp(info->name, "."))
		info->dot = 1;
	if (lstat(av[i], &stat) == -1)
	{
		info->no_existe = 1;
		info->errmsg = strerror(errno);
	}
	info->st = stat.st_mtime;
	info->mode = stat.st_mode;
	info->size = ft_itoa(stat.st_nlink);
	info->link = ft_itoa(stat.st_size);
	flag->maxl = 0;
	flag->maxs = 0;
}

void	creat_list_multi(char **av, t_info **head, t_gen *flag, int *x)
{
	t_info		*info;

	while (av[flag->i])
	{
		if (*x == 1)
		{
			info = (t_info *)malloc(sizeof(t_info));
			ft_init_list(info);
			*head = info;
			info->next = NULL;
			(*x)++;
		}
		else
		{
			info->next = (t_info *)malloc(sizeof(t_info));
			ft_init_list(info->next);
			info = info->next;
			info->next = NULL;
		}
		creat_list_multi_back(av, info, flag->i, flag);
		flag->i++;
	}
}

t_info	*multi_arg(char **av, t_gen *flag)
{
	t_info		*head;
	t_app		ap;
	int			x;

	x = 1;
	ap.dir = 0;
	ap.rep = 0;
	flag->maxl = 0;
	flag->maxn = 0;
	flag->maxg = 0;
	flag->maxs = 0;
	creat_list_multi(av, &head, flag, &x);
	if (x != 1)
	{
		ft_merge_multi(&head, flag);
		ft_multi_print(&head, flag, ap);
	}
	return (head);
}
