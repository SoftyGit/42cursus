/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:08:03 by dojeong           #+#    #+#             */
/*   Updated: 2023/09/27 20:40:58 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"
#include "envp.h"

void	init_envp(char **envp)
{
	int		num_envp;
	int		i;
	char	*envp_path;
	int		fd_envp;

	envp_path = "/var/tmp/.minishellrc";
	fd_envp = open(envp_path, O_RDWR | O_CREAT | O_TRUNC, 0644);
	num_envp = count_envp_from_array(envp);
	i = -1;
	while (++i < num_envp)
	{
		write(fd_envp, envp[i], ms_strlen(envp[i]));
		write(fd_envp, "\n", 1);
	}
	close(fd_envp);
}

void	free_envp(char **envp)
{
	int	num_envp;
	int	i;

	num_envp = count_envp_from_array(envp);
	i = 0;
	while (i < num_envp)
	{
		free(envp[i]);
		envp[i] = 0;
		i++;
	}
	free(envp);
	envp = 0;
}

int	add_envp(char *name, char *value)
{
	char	*temp;
	char	*new_envp;
	char	**new_envps;
	char	**old_envps;
	int		i;

	new_envp = ms_strjoin(name, "=");
	temp = ms_strjoin(new_envp, value);
	free(new_envp);
	new_envp = ms_strjoin(temp, "\n");
	free(temp);
	old_envps = read_envp();
	new_envps = malloc(sizeof(char *) * (count_envp_from_array(old_envps) + 2));
	if (new_envps == NULL)
		return (EXIT_FAILURE);
	i = -1;
	while (++i < count_envp_from_array(old_envps))
		new_envps[i] = old_envps[i];
	new_envps[i] = new_envp;
	new_envps[i + 1] = 0;
	write_and_free_envp(new_envps, old_envps);
	free(new_envp);
	free(new_envps);
	return (EXIT_SUCCESS);
}

int	del_envp(char *name)
{
	char	**new_envps;
	char	**old_envps;
	int		i;
	int		j;
	char	*temp;

	temp = find_envp(name);
	if (temp == NULL)
		return (EXIT_SUCCESS);
	free(temp);
	old_envps = read_envp();
	new_envps = malloc(sizeof(char *) * (count_envp_from_array(old_envps)));
	i = -1;
	j = 0;
	while (old_envps[++i] != NULL)
	{
		if (!(ms_strncmp(old_envps[i], name, ms_strlen(name)) == 0 && \
		old_envps[i][ms_strlen(name)] == '='))
			new_envps[j++] = old_envps[i];
	}
	new_envps[j] = 0;
	write_and_free_envp(new_envps, old_envps);
	return (EXIT_SUCCESS);
}

int	update_envp(char *name, char *value)
{
	int		i;
	char	*temp;
	char	*new_envp;
	char	**old_envp;

	temp = find_envp(name);
	if (temp == NULL)
		return (add_envp(name, value));
	free(temp);
	old_envp = read_envp();
	new_envp = ms_strjoin_4(name, "=", value, "\n");
	i = -1;
	while (++i < count_envp_from_file())
	{
		if (ms_strncmp(old_envp[i], name, ms_strlen(name)) == 0)
		{
			free(old_envp[i]);
			old_envp[i] = new_envp;
			break ;
		}
	}
	write_and_free_envp(old_envp, old_envp);
	return (EXIT_SUCCESS);
}
