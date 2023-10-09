/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 10:17:15 by dojeong           #+#    #+#             */
/*   Updated: 2023/09/27 20:56:17 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

//env.c
int	ms_env(char **args);

//echo.c
int	ms_echo(char **args);
int	is_flag(char *arg);

//pwd.c
int	ms_pwd(void);

//unset.c
int	ms_unset(char **args, int num_commands);

//cd.c
int	ms_cd(char **args, int num_commands);
int	cd_old(void);
int	cd_no_args(char **args);
int	merge_tilde(char *dir);
int	merge_dot(char *dir);
int	merge_dotdot(char *dir);
int	update_oldpwd(void);

//export.c
int	ms_export(char **args, int num_commands);

//exit.c
int	ms_exit(char **args);

#endif
