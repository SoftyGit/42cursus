/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fearingsoft <fearingsoft@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:18:13 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/12/17 14:15:08 by fearingsoft      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_per_c(const char **format, va_list *ap, size_t *len)
{
	char	val;

	val = va_arg(*ap, int);
	write(1, &val, 1);
	*len += 1;
	*format += 2;
}

void	ft_per_s(const char **format, va_list *ap, size_t *len)
{
	char	*str;

	str = va_arg(*ap, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		*len += 6;
	}
	else
	{
		write(1, str, ft_strlen(str));
		*len += ft_strlen(str);
	}
	*format += 2;
}

void	ft_per_p(const char **format, va_list *ap, size_t *len)
{
	unsigned long long	val;

	val = (unsigned long long)va_arg(*ap, void *);
	write(1, "0x", 2);
	if (!val)
		write(1, "0", 1);
	else
		ft_helper_hex_low(val, len);
	*len += 2 + (!val);
	*format += 2;
}

void	ft_per_diu(const char **format, va_list *ap, size_t *len)
{
	char	*str;

	if (!ft_strncmp(*format, "%d", 2) || !ft_strncmp(*format, "%i", 2))
		str = ft_itoa(va_arg(*ap, int));
	else
		str = ft_itoa_unsigned(va_arg(*ap, unsigned int));
	write(1, str, ft_strlen(str));
	*len += ft_strlen(str);
	free(str);
	*format += 2;
}
