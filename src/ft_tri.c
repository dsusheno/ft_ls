/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:26:24 by dsusheno          #+#    #+#             */
/*   Updated: 2016/03/04 16:26:27 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_lib.h"

void	ft_initlist(t_info **head, t_info **info)
{
	if (!(*head))
	{
		*info = (t_info *)malloc(sizeof(t_info));
		(*info)->no_existe = 0;
		(*info)->st = 0;
		(*info)->errmsg = NULL;
		(*info)->name = NULL;
		*head = *info;
		(*info)->next = NULL;
	}
	else
	{
		(*info)->next = (t_info *)malloc(sizeof(t_info));
		(*info) = (*info)->next;
		(*info)->no_existe = 0;
		(*info)->st = 0;
		(*info)->errmsg = NULL;
		(*info)->name = NULL;
		(*info)->next = NULL;
	}
}

void	ft_save_size(t_info **info, t_gen *flag, struct stat stat)
{
	(*info)->size = ft_itoa(stat.st_nlink);
	flag->maxl = flag->maxl < (int)ft_strlen((*info)->size) ?
		ft_strlen((*info)->size) : flag->maxl;
	(*info)->link = ft_itoa(stat.st_size);
	flag->maxs = flag->maxs < (int)ft_strlen((*info)->link) ?
		(ft_strlen((*info)->link)) : (flag->maxs);
	(*info)->st = stat.st_mtime;
	(*info)->nsec = stat.st_mtimespec.tv_nsec;
}

void	ft_add2(struct stat st, char **tmp, t_gen **flag, t_info **info)
{
	if (lstat(*tmp, &st) != -1)
	{
		(*flag)->block += st.st_blocks;
		ft_name(st, *flag, 0);
		ft_save_size(info, *flag, st);
	}
	else
	{
		(*info)->errmsg = strerror(errno);
		(*info)->size = (char *)malloc(1);
		(*info)->link = (char *)malloc(1);
	}
	(*info)->mode = st.st_mode;
}

t_info	*ft_addlist(DIR *dir, struct stat stat, char *tab, t_gen *flag)
{
	char			*tmp;
	struct dirent	*dp;
	t_info			*info;
	t_info			*head;

	head = NULL;
	flag->block = 0;
	while ((dp = readdir(dir)))
	{
		if ((flag->a == 1) ? 1 : dp->d_name[0] != '.')
		{
			ft_initlist(&head, &info);
			info->name = ft_strdup(dp->d_name);
			tmp = ft_strjoin_char(tab, dp->d_name, '/');
			ft_add2(stat, &tmp, &flag, &info);
			free(tmp);
		}
	}
	return (head);
}

t_info	*ft_tri(char *tab, t_gen *flag)
{
	DIR				*dir;
	struct stat		st;
	char			*tmp;
	static int		n_app;

	flag->maxl = 0;
	flag->maxn = 0;
	flag->maxg = 0;
	flag->maxs = 0;
	if (!(dir = opendir(tab)))
	{
		tmp = ft_strrchr(tab, '/');
		ft_putstr_fd("ft_ls: ", 2);
		tmp ? ft_putstr_fd(tmp + 1, 2) : ft_putstr_fd(tab, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putchar_fd('\n', 2);
		return (NULL);
	}
	flag->head = ft_addlist(dir, st, tab, flag);
	ft_print(tab, flag);
	closedir(dir);
	if (!n_app)
		ft_dir_list(flag, &n_app);
	return (flag->head);
}
