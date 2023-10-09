/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojeong <dojeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:22:03 by yongjale          #+#    #+#             */
/*   Updated: 2023/09/27 20:39:41 by dojeong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include "parse.h"
# include "minishell.h"

typedef struct s_env{
	size_t	temp;
	int		is_envp;
	int		is_word;
	int		is_cursh;
	char	*ret_str;
	char	*tmp_str;
	char	*tmp_chk;
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;
	char	*tmp4;
	char	*str;
	int		envp[MAX_COMMAND][2];
}			t_env;

//utils
int			ms_strncmp(const char *s1, const char *s2, size_t n);
char		*ms_strrchr(const char *s, int c);
char		*ms_strjoin(char const *s1, char const *s2);
size_t		ms_strlen(const char *s);

//utils2
size_t		ms_strlcpy(char *dst, const char *src, size_t dstsize);
void		free_char_array(char **arr);
int			ms_isalpha(int c);
int			ms_isdigit(int c);
long long	ms_atoi(const char *str);

//utils3
char		**ms_split(char const *s, char c);

//utils4
void		*ms_memset(void *b, int c, size_t len);
void		init_var(t_var *var, char *cmd, size_t max);
char		*make_word(char *start, char *end);
size_t		find_index(int str[MAX_COMMAND][2], size_t max);
char		*get_string(char *cmd, int a, int b, int mode);

//utils5
void		init_command(t_command *cmd);
void		init_job(t_job *job);
t_red_in	*make_in_index(t_command *command, t_red_in *red_in);
t_red_out	*make_out_index(t_command *command, t_red_out *red_out);
void		init_part_env(t_env *env);

//utils6
char		*ms_strcat(const char *dst, const char join, const char *src);
void		*ms_memcpy(void *dst, const void *src, size_t n);
void		*ms_free(t_job *job);
void		init_env(t_env *env, char *str, size_t max);

//utils7
char		*get_check(char *str, t_var *var);

//utils8
char		*ms_itoa(int n);
void		print_error(char *str);

//utils9
int			count_envp_from_file(void);
char		*get_find_envp(char *str);
int			get_quote_check(int c, t_var *var);
int			get_check_in_cursh(t_env *env, char *str);
void		get_merge_last_word(t_env *env, size_t i);

//utils10
void		get_string_single_quote(t_var *var, char *ret, char *cmd, int mode);
void		get_string_other(t_var *var, char *ret, char *cmd, int mode);
void		get_check_before_merge(t_env *env);
int			count_envp_from_array(char **envp);
void		get_free_envp(char **str);

//utils11
void		free_and_assign(char *str, char *new);
char		*ms_strjoin_4(char *str1, char *str2, char *str3, char *str4);

//draw_logo
void		init_minishell(void);

#endif
