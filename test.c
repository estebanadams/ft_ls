/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 13:56:52 by eleclet           #+#    #+#             */
/*   Updated: 2016/01/25 18:10:48 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int main(int argc,char **argv)
{
	t_lst *liste;	
	t_lst *ptr;
	liste = getinfo(argv[1]);
	ptr = liste;
	print(liste->next);
	//printlist(liste->next,findmax(liste->next, 1) , findmax(liste->next, 0));
	return (0);
}
