/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:20:19 by yongjale          #+#    #+#             */
/*   Updated: 2022/12/27 20:00:49 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/******************************************************************************/
/*** __HEADER__START **********************************************************/
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
/*** __HEADER__END ************************************************************/
/******************************************************************************/
/******************************************************************************/
/*** __FUNCTION__START ********************************************************/

/* ADDITIONAL__FUNCTION__START */
char	*ft_itoa_unsigned(unsigned int n);
/* ADDITIONAL__FUNCTION__END */

/* PRINT__FUNCTION__START */
int		ft_printf(const char *format, ...);
void	ft_per_c(const char **format, va_list *ap, size_t *len);
void	ft_per_s(const char **format, va_list *ap, size_t *en);
void	ft_per_p(const char **format, va_list *ap, size_t *len);
void	ft_per_diu(const char **format, va_list *ap, size_t *len);
void	ft_per_sxlx(const char **format, va_list *ap, size_t *len);
void	ft_nper(const char **format, size_t *len);
void	ft_helper_hex_hig(unsigned long long val, size_t *len);
void	ft_helper_hex_low(unsigned long long val, size_t *len);
/* PRINT__FUNCTION__END */

/*** __FUNCTION__END **********************************************************/
/******************************************************************************/

#endif