/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldferna <aldferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:00:28 by aldferna          #+#    #+#             */
/*   Updated: 2024/12/12 15:31:36 by aldferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a_to_b_above(t_struct **stack_a, t_struct **stack_b, int a_above,
		int b_above)
{
	while (a_above - 1 != 0 && b_above - 1 != 0)
	{
		ft_rr(stack_a, stack_b);
		a_above -= 1;
		b_above -= 1;
	}
	while (a_above - 1 > 0)
	{
		ft_rotate_a(stack_a, 1);
		a_above -= 1;
	}
	while (b_above - 1 > 0)
	{
		ft_rotate_b(stack_b, 1);
		b_above -= 1;
	}
	ft_push_b(stack_a, stack_b);
}

void	move_a_to_b_below(t_struct **stack_a, t_struct **stack_b, int a_below,
		int b_below)
{
	while (a_below != 0 && b_below != 0)
	{
		ft_rrr(stack_a, stack_b);
		a_below -= 1;
		b_below -= 1;
	}
	while (a_below > 0)
	{
		ft_reverse_rotate_a(stack_a, 1);
		a_below -= 1;
	}
	while (b_below > 0)
	{
		ft_reverse_rotate_b(stack_b, 1);
		b_below -= 1;
	}
	ft_push_b(stack_a, stack_b);
}

void	move_a_to_b_mix1(t_struct **stack_a, t_struct **stack_b, int a_above,
		int b_below)
{
	while (a_above - 1 > 0)
	{
		ft_rotate_a(stack_a, 1);
		a_above -= 1;
	}
	while (b_below > 0)
	{
		ft_reverse_rotate_b(stack_b, 1);
		b_below -= 1;
	}
	ft_push_b(stack_a, stack_b);
}

void	move_a_to_b_mix2(t_struct **stack_a, t_struct **stack_b, int a_below,
		int b_above)
{
	while (a_below != 0)
	{
		ft_reverse_rotate_a(stack_a, 1);
		a_below -= 1;
	}
	while (b_above - 1 != 0)
	{
		ft_rotate_b(stack_b, 1);
		b_above -= 1;
	}
	ft_push_b(stack_a, stack_b);
}

void	move_a_to_b(t_struct **stack_a, t_struct **stack_b)
{
	const int		half_b = (ft_structsize(*stack_b) + 1) / 2;
	const t_struct	*aux_iter = (*stack_a);
	int				below[2];
	int				above[2];

	while (aux_iter)
	{
		below[A] = ft_structsize(*stack_a) - aux_iter->index + 1;
		below[B] = ft_structsize(*stack_b) - aux_iter->target_index + 1;
		above[A] = aux_iter->index;
		above[B] = aux_iter->target_index;
		if (aux_iter->cheapest == 1)
		{
			if (aux_iter->above == 1 && aux_iter->target_index <= half_b)
				move_a_to_b_above(stack_a, stack_b, above[A], above[B]);
			else if (aux_iter->above == 0 && aux_iter->target_index > half_b)
				move_a_to_b_below(stack_a, stack_b, below[A], below[B]);
			else if (aux_iter->above == 1 && aux_iter->target_index > half_b)
				move_a_to_b_mix1(stack_a, stack_b, above[A], below[B]);
			else if (aux_iter->above == 0 && aux_iter->target_index <= half_b)
				move_a_to_b_mix2(stack_a, stack_b, below[A], above[B]);
			return ;
		}
		aux_iter = aux_iter->next;
	}
}
