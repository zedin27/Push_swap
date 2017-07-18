/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 21:59:04 by twalton           #+#    #+#             */
/*   Updated: 2017/07/05 21:59:04 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	more_error_management(int *arr)
{
	if (arr[0] == -4)
	{
		free(arr);
		write(2, "That number is too high!\n", 25);
		return (0);
	}
	if (arr[0] == -5)
	{
		free(arr);
		write(2, "That number is too low!\n", 24);
		return (0);
	}
	if (arr[0] == -6)
	{
		free(arr);
		write(2, "Try adding a number next to it\n", 31);
		return (0);
	}
	if (arr[0] == -7)
	{
		free(arr);
		write(2, "No leading zeroes...\n", 21);
		return (0);
	}
	return (1);
}

static int	error_management(int *arr)
{
	if (arr[0] == -1)
	{
		free(arr);
		write(2, "Invalid Argument(s)\n", 20);
		return (0);
	}
	if (arr[0] == -2)
	{
		free(arr);
		return (0);
	}
	if (arr[0] == -3)
	{
		free(arr);
		write(2, "Duplicate Argument(s)\n", 22);
		return (0);
	}
	if (arr[0] == -8)
	{
		free(arr);
		write(2, "just write '0'...\n", 18);
		return (0);
	}
	return (more_error_management(arr));
}

int			main(int ac, char **av)
{
	int		*arr;
	char	**strarr;

	if (!(arr = get_array(ac, av)))
	{
		write(2, "Memory Allocation Failed\n", 25);
		return (0);
	}
	if (arr[0] < 0)
		return (error_management(arr));
	if ((strarr = get_actions(arr)) < (char**)2)
	{
		if (strarr == (char**)1)
			write(1, "op limit may be exceeded...\n", 28);
		else
			write(1, "Memory Allocation Failed\n", 25);
		free(arr);
		return (1);
	}
	free(arr);
	put_actions(strarr);
	free_strarr(strarr);
}
