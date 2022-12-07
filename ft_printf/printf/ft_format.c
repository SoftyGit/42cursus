/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fearingsoft <fearingsoft@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:18:13 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/12/04 14:24:10 by fearingsoft      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void	ft_per_c(char **format, va_list *ap)
{
	va_arg(*ap, char *);
	write(1, *ap, 1);
	*format += 2;
}

void	ft_per_s(char **format, va_list *ap)
{
	va_arg(*ap, char *);
	write(1, *ap, ft_strlen(*ap));
	*format += 2;
}

void	ft_per_p(char **format, va_list *ap)
{
	va_arg(*ap, char *);
	write(1, *ap, ft_strlen(*ap));
	*format += 2;
}