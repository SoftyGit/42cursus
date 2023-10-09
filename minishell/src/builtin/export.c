/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:23:01 by dojeong           #+#    #+#             */
/*   Updated: 2023/09/27 21:03:56 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"
#include "envp.h"
#include "utils.h"

int	is_parameter(char *str)
{
	if (ms_isdigit(str[0]) == 1)
		return (EXIT_FAILURE);
	while (*str != '=')
	{
		if (!(ms_isalpha(*str) == 1 || ms_isdigit(*str) == 1))
			return (EXIT_FAILURE);
		str++;
	}
	return (EXIT_SUCCESS);
}

char	**devide_word(char *str, char del)
{
	int		i;
	char	**ret;
	int		len_str;

	i = 0;
	len_str = ms_strlen(str);
	while (str[i] != del)
		i++;
	ret = malloc(sizeof(char *) * 3);
	ret[2] = 0;
	ret[0] = malloc(sizeof(char) * (i + 1));
	ret[0][i] = 0;
	ret[1] = malloc(sizeof(char) * (len_str - i));
	ret[1][len_str - i - 1] = 0;
	ms_strlcpy(ret[0], str, i + 1);
	ms_strlcpy(ret[1], str + i + 1, len_str - i);
	return (ret);
}

int	ms_export(char **args, int num_commands)
{
	int		i;
	int		flag;
	char	**temp;

	flag = EXIT_SUCCESS;
	if (num_commands > 1)
		return (EXIT_SUCCESS);
	if (args == NULL || args[0] == NULL)
		return (ms_env(args));
	i = -1;
	while (args[++i])
	{
		if (is_parameter(args[i]) == EXIT_FAILURE)
		{
			printf("%s: not a valid identifier\n", args[i]);
			flag = EXIT_FAILURE;
		}
		else
		{
			temp = devide_word(args[i], '=');
			update_envp(temp[0], temp[1]);
			free_char_array(temp);
		}
	}
	return (flag);
}
