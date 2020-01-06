/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saad <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 22:56:51 by saad              #+#    #+#             */
/*   Updated: 2019/07/19 03:52:47 by sael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"

void	min(t_block *tetris, t_limit *limit, int i)
{
	int		j;

	limit->miny = TPP[i][0].y;
	limit->minx = TPP[i][0].x;
	j = -1;
	while (++j < 4)
	{
		if (limit->minx > TPP[i][j].x)
			limit->minx = TPP[i][j].x;
		if (limit->miny > TPP[i][j].y)
			limit->miny = TPP[i][j].y;
	}
}

void	max(t_block *tetris, t_limit *limit, int i)
{
	int j;

	limit->maxy = TPP[i][0].y;
	limit->maxx = TPP[i][0].x;
	j = -1;
	while (++j < 4)
	{
		if (limit->maxx < TPP[i][j].x)
			limit->maxx = TPP[i][j].x;
		if (limit->maxy < TPP[i][j].y)
			limit->maxy = TPP[i][j].y;
	}
}

void	slideone(t_block *tetris, t_limit *limit, int i)
{
	int j;

	min(tetris, limit, i);
	j = -1;
	while (++j < 4)
	{
		TPP[i][j].x = TPP[i][j].x - limit->minx;
		TPP[i][j].y = TPP[i][j].y - limit->miny;
	}
	min(tetris, limit, i);
}

void	slide(t_block *tetris, t_limit *limit)
{
	int j;
	int i;

	i = -1;
	while (++i <= tetris->blocks)
	{
		min(tetris, limit, i);
		j = -1;
		while (++j < 4)
		{
			TPP[i][j].x = TPP[i][j].x - limit->minx;
			TPP[i][j].y = TPP[i][j].y - limit->miny;
		}
		min(tetris, limit, i);
	}
}
