/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 01:26:04 by yomyom            #+#    #+#             */
/*   Updated: 2023/09/27 20:40:58 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"
#include "envp.h"
#include "get_next_line.h"
#include <errno.h>

char	*find_envp(char *name)
{
	char	**envp;
	int		name_len;
	char	*ret;

	if (name[0] == '?' && name[1] == '\0')
		return (ms_itoa(g_exit_status));
	name_len = ms_strlen(name);
	envp = read_envp();
	ret = find_envp2(envp, name, name_len);
	free_envp(envp);
	return (ret);
}

char	*find_envp2(char **envp, char *name, int name_len)
{
	int		i;
	int		value_len;
	char	*ret;

	i = 0;
	while (i < count_envp_from_file() && envp[i] != NULL)
	{
		if (ms_strncmp(envp[i], name, name_len) == 0 && \
		envp[i][name_len] == '=')
		{
			value_len = 0;
			while (envp[i][name_len + 1 + value_len] != '\n')
				value_len++;
			ret = malloc(sizeof(char) * value_len + 1);
			ret[value_len] = 0;
			ms_memcpy(ret, envp[i] + name_len + 1, value_len);
			return (ret);
		}
		i++;
	}
	return (0);
}

int	write_envp(char **envp)
{
	int	envp_fd;
	int	i;
	int	num_envp;

	num_envp = count_envp_from_array(envp);
	envp_fd = open("/var/tmp/.minishellrc", O_RDWR | O_TRUNC, 0644);
	i = 0;
	while (i < num_envp)
	{
		write(envp_fd, envp[i], ms_strlen(envp[i]));
		i++;
	}
	close(envp_fd);
	return (EXIT_SUCCESS);
}

char	**read_envp(void)
{
	int		envp_fd;
	char	**new_envp;
	int		i;
	int		num_envp;

	envp_fd = open("/var/tmp/.minishellrc", O_RDONLY, 0644);
	num_envp = count_envp_from_file();
	new_envp = malloc(sizeof(char *) * (num_envp + 1));
	new_envp[num_envp] = 0;
	i = 0;
	while (i < num_envp)
	{
		new_envp[i] = get_next_line(envp_fd);
		i++;
	}
	close(envp_fd);
	return (new_envp);
}

void	write_and_free_envp(char **wenvp, char **fenvp)
{
	write_envp(wenvp);
	free_envp(fenvp);
}
