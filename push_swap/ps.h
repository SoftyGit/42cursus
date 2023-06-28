/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:36:40 by yongjale          #+#    #+#             */
/*   Updated: 2023/06/28 14:21:49 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

typedef struct	s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}t_node;

typedef struct	s_stack
{
	struct s_node	*top;
	struct s_node	*bot;
	int	length;
}t_stack;

#endif