/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fearingsoft <fearingsoft@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:18:13 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/12/17 14:13:33 by fearingsoft      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_per_sxlx(const char **format, va_list *ap, size_t *len)
{	
	unsigned int	val;

	val = va_arg(*ap, unsigned int);
	if (!val)
		write(1, "0", 1);
	else if (!ft_strncmp(*format, "%x", 2))
		ft_helper_hex_low(val, len);
	else
		ft_helper_hex_hig(val, len);
	*len += (!val);
	*format += 2;
}

void	ft_nper(const char **format, size_t	*len)
{
	if (!ft_strncmp(*format, "%%", 2))
		write(1, "%", 1);
	else
		write(1, *format, 1);
	*len += 1;
	*format += 1 + !ft_strncmp(*format, "%%", 2);
}
