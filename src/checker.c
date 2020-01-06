/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saad <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 22:47:20 by saad              #+#    #+#             */
/*   Updated: 2019/07/22 00:05:03 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"

void	check_contact(int k, t_block tetris, int *contactnb)
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (TP[k][j].x == TP[k][i].x + 1 && TP[k][j].y == TP[k][i].y)
				(*contactnb)++;
			if (TP[k][j].x == TP[k][i].x - 1 && TP[k][j].y == TP[k][i].y)
				(*contactnb)++;
			if (TP[k][j].x == TP[k][i].x && TP[k][j].y == TP[k][i].y + 1)
				(*contactnb)++;
			if (TP[k][j].x == TP[k][i].x && TP[k][j].y == TP[k][i].y - 1)
				(*contactnb)++;
		}
	}
}

int		contact(t_block tetris)
{
	int contactnb;
	int k;

	k = -1;
	while (++k <= TB)
	{
		contactnb = 0;
		check_contact(k, tetris, &contactnb);
		if (contactnb != 6 && contactnb != 8)
			return (0);
	}
	return (contactnb);
}

void	map(t_block *tetris, char *line, int tetend)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '#')
		{
			TPP[TPB][TPHC].x = i;
			TPP[TPB][TPHC].y = tetend - 1;
			if ((TPHC)++ >= 4)
				ft_exit();
		}
	}
}

void	checker(t_block *tetris, char *line, int *tetend)
{
	int i;

	i = 0;
	while (line[i] != '\n')
		if (line[i] == '.' || line[i] == '#')
			i++;
		else
			ft_exit();
	if (i == 4 && line[4] == '\n' && *tetend <= 4)
		(*tetend)++;
	else if (i == 0 && *tetend == 4 && line[0] == '\n')
	{
		*tetend = 0;
		if (TPHC != 4 || ++TPB > 25)
			ft_exit();
		TPHC = 0;
	}
	else
		ft_exit();
}

int		mainchecker(t_block *tetris, int fd)
{
	int		tetend;
	char	**line;
	char	*red;
	int		j;

	j = -1;
	tetend = 0;
	checkfile(&red, fd);
	line = ft_strsplit(red, '\n');
	free(red);
	while (line[++j])
	{
		checker(tetris, line[j], &tetend);
		map(tetris, line[j], tetend);
		ft_strdel(&line[j]);
	}
	if (tetend != 4 || TPHC != 4)
		ft_exit();
	if (line != NULL)
		free_tab(&line, j);
	if (contact(*tetris) != 6 && contact(*tetris) != 8)
		ft_exit();
	return (1);
}
