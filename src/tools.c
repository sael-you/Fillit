/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfirst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-kobi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 00:01:32 by yel-kobi          #+#    #+#             */
/*   Updated: 2019/07/22 00:01:35 by yel-kobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fillit.h"

void	checkfile(char **red, int fd)
{
	int		i;
	int		ret;
	char	rd[546];

	i = 0;
	if ((ret = read(fd, rd, 546)) < 546)
	{
		while (i < ret)
			if (rd[i] == '.' || rd[i] == '#' || rd[i] == '\n')
				i++;
			else
			{
				close(fd);
				ft_exit();
			}
	}
	*red = ft_strncpy(ft_strnew(ret), rd, ret);
	close(fd);
}

void	free_tab(char ***tab, size_t size)
{
	while (size--)
		ft_strdel(&tab[0][size]);
	free(*tab);
	*tab = NULL;
}

void	reset_grid(char **grid, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
		ft_memset(grid[i++], '.', size);
}

void	ft_exit(void)
{
	ft_putendl("error");
	exit(0);
}
