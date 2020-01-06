/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 04:23:15 by yel-kobi          #+#    #+#             */
/*   Updated: 2019/07/19 04:27:50 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "fillit.h"
# include "libft.h"

typedef struct	s_hash
{
	int x;
	int y;

}				t_hash;

typedef struct	s_block
{
	t_hash		pos[26][4];
	int			blocks;
	int			grid_size;
	int			hash_count;
	char		**grid;
}				t_block;

typedef struct	s_limit
{
	int minx;
	int miny;
	int maxx;
	int maxy;
}				t_limit;

# define TP tetris.pos
# define TPP tetris->pos
# define TG tetris.grid
# define TPG tetris->grid
# define TPGS tetris->grid_size
# define TGS tetris.grid_size
# define THC tetris.hash_count
# define TPHC tetris->hash_count
# define TB tetris.blocks
# define TPB tetris->blocks

int				mainchecker(t_block *tetris, int fd);
void			slide(t_block *tetris, t_limit *limit);
void			slideone(t_block *tetris, t_limit *limit, int i);
void			slidebutone(t_block *tetris, t_limit *limit, int expt);
void			max(t_block *tetris, t_limit *limit, int i);
void			min(t_block *tetris, t_limit *limit, int i);
void			solver(t_block *tetris, t_limit *limit);
int				trydrag(t_block *tetris, t_limit *limit, int i);
void			dragger(t_block *tetris, t_limit *limit, int index);
void			free_tab(char ***tab, size_t size);
void			reset_grid(char **grid, size_t size);
void			ft_exit(void);
void			map(t_block *tetris, char *line, int tetend);
void			checker(t_block *tetris, char *line, int *tetend);
void			checkfile(char **rd, int fd);

#endif
