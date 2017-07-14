/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_n.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 11:30:28 by twalton           #+#    #+#             */
/*   Updated: 2017/07/11 11:30:28 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_n(int *arr, int f_rot, int b_rot)
{
	while (f_rot)
	{
		rot_elem(arr, '+');
		f_rot--;
	}
	while (b_rot)
	{
		rot_elem(arr, '-');
		b_rot--;
	}
}
