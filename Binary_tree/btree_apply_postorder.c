/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_postorder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:17:46 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/03 22:53:45 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./btree.h"

void	btree_apply_postorder(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL)
		return ;
	if (root->left)
		btree_apply_postorder(root->left, applyf);
	if (root->right)
		btree_apply_postorder(root->right, applyf);
	applyf(root->item);
}
