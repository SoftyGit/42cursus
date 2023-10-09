/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:10:52 by yongjale          #+#    #+#             */
/*   Updated: 2023/09/24 16:13:51 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"

void	*ms_memset(void *b, int c, size_t len)
{
	void	*ret;

	ret = b;
	while (len--)
		*((char *)b++) = c;
	return (ret);
}

void	init_var(t_var *var, char *cmd, size_t max)
{
	size_t	i;

	i = 0;
	var->temp = 0;
	var->type = 0;
	var->is_word = 0;
	var->is_quot = 0;
	var->is_file = 0;
	var->is_pipe = 0;
	var->count = 0;
	var->cmd = cmd;
	while (i < max)
	{
		var->word[i][0] = -1;
		var->word[i][1] = -1;
		var->file[0][i][0] = -1;
		var->file[1][i][0] = -1;
		var->file[2][i][0] = -1;
		var->file[3][i][0] = -1;
		var->file[0][i][1] = -1;
		var->file[1][i][1] = -1;
		var->file[2][i][1] = -1;
		var->file[3][i][1] = -1;
		i++;
	}
}

char	*make_word(char *start, char *end)
{
	size_t	len;
	size_t	i;
	char	*ret;

	i = 0;
	len = end - start + 2;
	if (len == 1)
		return (NULL);
	ret = (char *)malloc(len);
	while (len-- != 1)
	{
		ret[i] = *start;
		start++;
		i++;
	}
	ret[i] = 0;
	return (ret);
}

size_t	find_index(int str[MAX_COMMAND][2], size_t max)
{
	size_t	i;

	i = 0;
	while (i < max)
	{
		if (str[i][1] == -1)
			return (i);
		i++;
	}
	return (max - 1);
}

char	*get_string(char *cmd, int a, int b, int mode)
{
	size_t	size;
	t_var	var;
	char	*ret;

	init_var(&var, NULL, MAX_COMMAND);
	if (a > b || (a == -1 && b == -1))
		return (NULL);
	size = b - a + 1;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	while (var.count < size)
	{
		if (var.is_quot && (cmd[a + var.count] == var.is_quot))
			get_string_single_quote(&var, ret, &cmd[a], mode);
		else if (!var.is_quot && (cmd[a + var.count] == '\''
				|| cmd[a + var.count] == '\"'))
			get_string_other(&var, ret, &cmd[a], mode);
		else
			ret[(var.temp)++] = cmd[a + var.count];
		var.count++;
	}
	ret[var.temp] = 0;
	if (mode)
		ret = get_check(ret, &var);
	return (ret);
}
