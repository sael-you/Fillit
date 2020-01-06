/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-you <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:52:25 by sael-you          #+#    #+#             */
/*   Updated: 2019/03/25 14:53:56 by sael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

int		ft_sqrt(int nb)
{
	int sqrt;

	sqrt = 1;
	if (nb <= 0)
		return (0);
	while (sqrt * sqrt < nb)
		(sqrt++);
	if (sqrt * sqrt == nb)
		return (sqrt);
	else
		return (0);
}
