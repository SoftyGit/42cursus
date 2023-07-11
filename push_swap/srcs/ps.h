/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:36:40 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/11 22:35:06 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# define INT_MAX 2147483647
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				num;
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}t_node;

typedef struct s_stack
{
	struct s_node	*top;
	struct s_node	*bot;
	int				length;
}t_stack;

#endif