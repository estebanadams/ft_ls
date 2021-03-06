/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 11:21:42 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/03 17:53:37 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		rec_control(t_lst *lst, char *param)
{
	while (lst)
	{
		rec_main(param, lst->info.name);
		if (lst->next)
			lst = lst->next;
		else
			return (0);
	}
	return (0);
}

int		rec_main(char *param, char *path)
{
	t_lst *file;
	t_lst *start;

	file = NULL;
	if (!(file = getinfo(path)))
	{
		permdenied(path);
		return (0);
	}
	else
	{
		start = file;
		printf("\n%s:\n", path);
		sortfunc(param, &start, 0, path);
	}
	while (file->next)
	{
		file = file->next;
		if (file->info.perm[0] == 'd' && ft_strcmp(file->info.name, ".") != 0 &&
			ft_strcmp(file->info.name, "..") != 0)
		{
			rec_main(param, getpath(path, file->info.name));
		}
	}
	return (0);
}
