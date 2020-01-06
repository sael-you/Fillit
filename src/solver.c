/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-you <sael-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:37:04 by saad              #+#    #+#             */
/*   Updated: 2019/07/21 16:10:51 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"

char	**create_grid(int blocknb)
{
	char	**grid;
	int		i;

	i = 0;
	if (!(grid = (char **)malloc(sizeof(char *) * (blocknb))))
		return (NULL);
	while (i < blocknb)
	{
		if (!(grid[i] = malloc(blocknb + 1)))
			while (i--)
			{
				ft_strdel(&grid[i]);
				return (NULL);
			}
		ft_memset(grid[i], '.', blocknb);
		grid[i][blocknb] = 0;
		i++;
	}
	return (grid);
}

int		parser(t_block *tetris)
{
	int i;
	int j;

	i = 0;
	while (i <= tetris->blocks)
	{
		j = -1;
		while (++j < 4)
		{
			if (TPG[TPP[i][j].y][TPP[i][j].x] == '.')
				TPG[TPP[i][j].y][TPP[i][j].x] = 'A' + i;
			else if (TPG[TPP[i][j].y][TPP[i][j].x] != '.')
			{
				reset_grid(TPG, TPGS);
				return (i);
			}
		}
		i++;
	}
	return (27);
}

void	dragger(t_block *tetris, t_limit *limit, int index)
{
	int i;

	i = -1;
	while (++i <= index)
	{
		if (!(trydrag(tetris, limit, index - i)))
		{
			slideone(tetris, limit, index - i);
			reset_grid(TPG, TPGS);
		}
		else
			break ;
	}
	if (i > index)
	{
		TPGS++;
		slide(tetris, limit);
	}
}

void	solver(t_block *tetris, t_limit *limit)
{
	int index;
	int size;

	size = TPGS;
	while ((index = parser(tetris)) != 27)
	{
		dragger(tetris, limit, index);
		if (size < TPGS)
		{
			free_tab(&TPG, size);
			if (!(TPG = create_grid(TPGS)))
				exit(1);
			size++;
		}
		else
			reset_grid(TPG, size);
	}
}

int		main(int argc, char **argv)
{
	int			j;
	t_block		tetris;
	t_limit		limit;

	j = 0;
	if (argc == 2)
		if (mainchecker(&tetris, open(argv[1], O_RDONLY)))
		{
			slide(&tetris, &limit);
			max(&tetris, &limit, 0);
			while (!(TGS = ft_sqrt(((tetris.blocks + 1) * 4) - j)))
				j++;
			while (TGS <= limit.maxx || TGS <= limit.maxy)
				TGS++;
			if (!(TG = create_grid(TGS)))
				return (0);
			solver(&tetris, &limit);
			j = 0;
			while (j < TGS)
				ft_putendl(TG[j++]);
			free_tab(&TG, TGS);
			return (0);
		}
	ft_putendl("usage: ./fillit tetris_file");
	return (0);
}
