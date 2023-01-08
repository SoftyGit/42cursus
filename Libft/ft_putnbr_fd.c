/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fearingsoft <fearingsoft@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:25:57 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/11/26 13:25:28 by fearingsoft      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_putnbr_fd_helper(long val, int fd)
{
	char	add;

	if (val / 10)
		ft_putnbr_fd_helper(val / 10, fd);
	add = 48 + val % 10;
	write(fd, &add, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	val;
	char	add;

	val = (long) n * ((n > 0) + (n < 0) * -1);
	add = 48 - 3 * (n < 0);
	if (n < 0)
		write(fd, &add, n < 0);
	ft_putnbr_fd_helper(val, fd);
}
