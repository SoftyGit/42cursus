/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 23:30:59 by yomyom            #+#    #+#             */
/*   Updated: 2023/09/27 20:40:54 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"

char static	*get_string_itoa(int n)
{
	int		digit;
	int		i;
	int		temp;
	char	*arr;

	i = 0;
	digit = 1;
	temp = n;
	while (temp >= 10)
	{
		temp /= 10;
		digit++;
	}
	arr = malloc(sizeof(char) * (digit + 1));
	if (arr == 0)
		return (0);
	i = 0;
	while (i < digit)
	{
		arr[digit - 1 - i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	arr[digit] = '\0';
	return (arr);
}

char static	*get_string_n(int n)
{
	int		digit;
	int		i;
	int		temp;
	char	*arr;

	i = 0;
	digit = 1;
	temp = n;
	while (temp >= 10)
	{
		temp /= 10;
		digit++;
	}
	arr = malloc(sizeof(char) * (digit + 2));
	if (arr == 0)
		return (0);
	i = 0;
	while (i < digit)
	{
		arr[digit - (i++)] = n % 10 + '0';
		n /= 10;
	}
	arr[digit + 1] = '\0';
	arr[0] = '-';
	return (arr);
}

char static	*min_max(void)
{
	char	*arr;

	arr = malloc(sizeof(char) * 12);
	if (arr == 0)
		return (0);
	arr[0] = '-';
	arr[1] = '2';
	arr[2] = '1';
	arr[3] = '4';
	arr[4] = '7';
	arr[5] = '4';
	arr[6] = '8';
	arr[7] = '3';
	arr[8] = '6';
	arr[9] = '4';
	arr[10] = '8';
	arr[11] = '\0';
	return (arr);
}

char	*ms_itoa(int n)
{
	char	*arr;

	if (n == -2147483648)
	{
		arr = min_max();
		return (arr);
	}
	if (n >= 0)
		arr = get_string_itoa(n);
	else
		arr = get_string_n(-1 * n);
	return (arr);
}

void	print_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
