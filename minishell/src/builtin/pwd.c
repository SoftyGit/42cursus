/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:12:36 by dojeong           #+#    #+#             */
/*   Updated: 2023/09/27 20:40:55 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"
#include "utils.h"

int	ms_pwd(void)
{
	char	*buffer;

	buffer = getcwd(NULL, 0);
	printf("%s\n", buffer);
	free(buffer);
	return (0);
}
