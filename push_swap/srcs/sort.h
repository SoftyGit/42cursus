/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:13:05 by yongjale          #+#    #+#             */
/*   Updated: 2023/07/12 08:45:54 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "ps.h"
# include "order.h"

void	sortlength(t_stack *a, t_stack *b);
void	sort2(t_stack *a);
void	sort3(t_stack *a);
void	sort4(t_stack *a, t_stack *b);
void	sort5(t_stack *a, t_stack *b);
void	sort_a2b(t_stack *a, t_stack *b, int chunk);
void	sort_b2a(t_stack *a, t_stack *b);

#endif  