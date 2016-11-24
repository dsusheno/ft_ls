/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:25:40 by dsusheno          #+#    #+#             */
/*   Updated: 2016/03/04 16:25:42 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_lib.h"

void	ft_name(struct stat stat, t_gen *flag, int m)
{
	struct passwd	*pwd;
	struct group	*grp;

	if (!(pwd = getpwuid(stat.st_uid)) ||
			!(grp = getgrgid(stat.st_gid)))
	{
		ft_sp_str(0, pwd->pw_name, flag->maxn, 2);
		ft_sp_nbr(2, stat.st_gid, 2);
	}
	else
	{
		if (m == 0)
		{
			flag->maxn = flag->maxn < (int)ft_strlen(pwd->pw_name) ?
					ft_strlen(pwd->pw_name) : flag->maxn;
			flag->maxg = flag->maxg < (int)ft_strlen(grp->gr_name) ?
					ft_strlen(grp->gr_name) : flag->maxg;
		}
		else
		{
			ft_sp_str(0, pwd->pw_name, flag->maxn, 2);
			ft_sp_str(2, grp->gr_name, flag->maxg, 2);
		}
	}
}

void	ft_print_l(t_info *info, char *tmp, struct stat stat, t_gen *flag)
{
	char	buf[1025];
	size_t	len;

	ft_mode(stat);
	ft_sp_str(flag->maxl, info->size, 1, 1);
	ft_name(stat, flag, 1);
	ft_putstr("  ");
	if (S_ISBLK(stat.st_mode) || S_ISCHR(stat.st_mode))
	{
		ft_sp_nbr(7, major(stat.st_rdev), 0);
		ft_putchar(',');
		ft_sp_nbr(4, minor(stat.st_rdev), 0);
	}
	else
		ft_sp_str(flag->maxs, info->link, 0, 1);
	ft_time(info->st, flag);
	ft_sp_str(1, info->name, 0, 1);
	if (S_ISLNK(stat.st_mode))
	{
		len = readlink(tmp, buf, 1024);
		buf[len] = '\0';
		ft_putstr(" -> ");
		ft_putstr(buf);
	}
}

void	ft_print2(t_info *info, char *tab, t_gen *flag)
{
	char			*tmp;
	char			*tmp2;
	struct stat		st;
	int				lst;

	if (tab)
		tmp = ft_strjoin_char(tab, info->name, '/');
	else
		tmp = ft_strdup(info->name);
	lst = lstat(tmp, &st);
	if (flag->l == 1 && lst != -1)
		ft_print_l(info, tmp, st, flag);
	else if (flag->l == 1 && lst == -1)
	{
		tmp2 = ft_strrchr(tmp, '/');
		ft_putstr_fd("ft_ls: ", 2);
		tmp2 ? ft_putstr_fd(tmp2 + 1, 2) : ft_putstr_fd(tmp, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
	}
	else
		ft_putstr(info->name);
	ft_putstr("\n");
	free(tmp);
	tmp = NULL;
}

void	ft_print(char *tab, t_gen *flag)
{
	t_info			*info;

	if (flag->head)
	{
		if (flag->l == 1 && !flag->head->errmsg)
		{
			ft_putstr("total ");
			ft_putnbr(flag->block);
			ft_putstr("\n");
		}
		if (flag->f != 1)
		{
			ft_mergesort(&(flag->head), flag->r, 0);
			if (flag->t == 1)
				ft_mergesort(&(flag->head), flag->r, 1);
		}
		info = flag->head;
		while (info != NULL)
		{
			ft_print2(info, tab, flag);
			free(info->size);
			free(info->link);
			info = info->next;
		}
	}
}
