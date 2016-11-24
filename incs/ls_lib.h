/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:29:51 by dsusheno          #+#    #+#             */
/*   Updated: 2016/03/03 15:29:58 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_LIB_H
# define LS_LIB_H
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include "libft.h"
# include <errno.h>
# include <string.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <sys/types.h>
# include <stdio.h>

typedef struct		s_info
{
	int				dot;
	int				no_existe;
	long int		st;
	int				is_link;
	char			*link;
	char			*size;
	long int		nsec;
	char			*name;
	char			*errmsg;
	struct s_info	*next;
	mode_t			mode;
}					t_info;

typedef	struct		s_gen
{
	int				r;
	int				a;
	int				t;
	int				tt;
	int				rr;
	int				l;
	int				i;
	int				f;
	int				n_argc;
	int				maxl;
	int				maxn;
	int				maxg;
	int				maxs;
	int				block;
	char			symb;
	t_info			*head;
}					t_gen;

typedef	struct		s_app
{
	int				nb_app_n;
	int				nb_app;
	char			*for_stat;
	int				dir;
	int				rep;
}					t_app;

void				ft_read_br(char *tab, t_gen *flag, t_app *ap);
int					ft_flag(char **av, t_gen *f, int x);
void				ft_is_link(t_info **head);
void				ft_sort_existe(t_info **headref);
t_info				*ms_time(t_info *l1, t_info *l2, int r);
void				ft_merge_multi(t_info **head, t_gen *flag);
void				ft_multi_print(t_info **head, t_gen *flag, t_app ap);
void				ft_br(char *tab, t_gen *flag, t_app *ap);
t_info				*multi_arg(char **av, t_gen *flag);
void				ft_mode(struct stat stat);
void				ft_time(long int st, t_gen *flag);
void				ft_dir_list(t_gen *flag, int *n_app);
void				ft_add2(struct stat st, char **tmp,
		t_gen **flag, t_info **info);
t_info				*ft_tri(char *tab, t_gen *flag);
void				ft_name(struct stat stat, t_gen *flag, int m);
void				ft_print2(t_info *info, char *name, t_gen *flag);
void				ft_print(char *tab, t_gen *flag);
void				ft_sp_str(int sp1, char *str, int sp2, int mod);
void				ft_sp_nbr(int sp1, int nbr, int sp2);
void				ft_mergesort(t_info **headref, int r, int ift);

#endif
