/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_inorder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:13:14 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/03 21:15:41 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./btree.h"

void	btree_apply_inorder(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL)
		return ;
	if (root->left)
		btree_apply_inorder(root->left, applyf);
	applyf(root->item);
	if (root->right)
		btree_apply_inorder(root->right, applyf);
}
