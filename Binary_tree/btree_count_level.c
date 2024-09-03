/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_count_level.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:24:45 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/03 22:30:14 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

int	btree_count_level(t_btree *root)
{
	int	left;
	int	reight;

	if (root)
	{
		left = btree_count_level(root->left);
		reight = btree_count_level(root->right);
		if (left > reight)
			return (left + 1);
		else
			return (reight + 1);
	}
	else
		return (0);
}
