/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fearingsoft <fearingsoft@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:15:27 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/12/17 14:13:37 by fearingsoft      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	len;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (!ft_strncmp(format, "%c", 2))
			ft_per_c(&format, &ap, &len);
		else if (!ft_strncmp(format, "%s", 2))
			ft_per_s(&format, &ap, &len);
		else if (!ft_strncmp(format, "%p", 2))
			ft_per_p(&format, &ap, &len);
		else if (!ft_strncmp(format, "%d", 2) || !ft_strncmp(format, "%i", 2)
			|| !ft_strncmp(format, "%u", 2))
			ft_per_diu(&format, &ap, &len);
		else if (!ft_strncmp(format, "%x", 2) || !ft_strncmp(format, "%X", 2))
			ft_per_sxlx(&format, &ap, &len);
		else
			ft_nper(&format, &len);
	}
	va_end(ap);
	return (len);
}
