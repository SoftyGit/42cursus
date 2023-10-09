/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:10:14 by dojeong           #+#    #+#             */
/*   Updated: 2023/09/24 12:59:04 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVP_H
# define ENVP_H

# include <fcntl.h>

//envp.c
void	init_envp(char **envp);
void	free_envp(char **envp);
int		add_envp(char *name, char *value);
int		del_envp(char *name);
int		update_envp(char *name, char *value);

//envp2.c
char	*find_envp(char *name);
char	*find_envp2(char **envp, char *name, int name_len);
char	**read_envp(void);
int		write_envp(char **envp);
void	write_and_free_envp(char **wenvp, char **fenvp);

#endif
