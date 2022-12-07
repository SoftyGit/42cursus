/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fearingsoft <fearingsoft@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:15:27 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/12/04 14:21:17 by fearingsoft      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "../libft/ft_strncmp.c"
#include "./ft_format.c"
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	
	va_start(ap, format);
	while (*format)
	{
		if (!ft_strncmp(format, "%%c", 2))
			ft_format(&format, &ap);
		else if (!ft_strncmp(format, "%%s", 2))
			ft_format(&format);
	}
	
	va_arg(ap, char *);
	va_end(ap);
	return (strlen(format));
}

int main()
{
	ft_printf("aa","bb","c");
}
