/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-you <sael-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:37:24 by saad              #+#    #+#             */
/*   Updated: 2019/07/19 03:51:11 by sael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"

void	dragside(t_block *tetris, t_limit *limit, int i)
{
	int k;

	k = -1;
	while (++k < 4)
		TPP[i][k].x = TPP[i][k].x + 1;
	min(tetris, limit, i);
	max(tetris, limit, i);
}

void	dragdown(t_block *tetris, t_limit *limit, int i)
{
	int k;

	k = -1;
	while (++k < 4)
	{
		TPP[i][k].x = TPP[i][k].x - limit->minx;
		TPP[i][k].y = TPP[i][k].y + 1;
	}
	min(tetris, limit, i);
	max(tetris, limit, i);
}

int		trydrag(t_block *tetris, t_limit *limit, int i)
{
	min(tetris, limit, i);
	max(tetris, limit, i);
	if (limit->maxx + 1 < TPGS)
	{
		dragside(tetris, limit, i);
		return (1);
	}
	else if (limit->maxy + 1 < TPGS)
	{
		dragdown(tetris, limit, i);
		return (1);
	}
	return (0);
}
