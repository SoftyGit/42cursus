/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils11.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 01:01:21 by yomyom            #+#    #+#             */
/*   Updated: 2023/09/27 20:40:53 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parse.h"

void	free_and_assign(char *str, char *new)
{
	free(str);
	str = new;
}

char	*ms_strjoin_4(char *str1, char *str2, char *str3, char *str4)
{
	char	*temp1;
	char	*temp2;
	char	*temp3;

	temp1 = ms_strjoin(str1, str2);
	temp2 = ms_strjoin(temp1, str3);
	temp3 = ms_strjoin(temp2, str4);
	free(temp1);
	free(temp2);
	temp1 = 0;
	temp2 = 0;
	return (temp3);
}
