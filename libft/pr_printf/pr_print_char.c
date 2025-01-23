/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:15:19 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/19 22:15:19 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pr_printf.h"

int	pr_print_char(int c)
{
	return (write(1, &c, 1));
}