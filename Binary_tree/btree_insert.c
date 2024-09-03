/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:19:25 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/03 22:53:25 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	btree_insert(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	t_btree	*node;

	if (*root == NULL)
		*root = create_node(item);
	node = *root;
	if ((cmpf)(item, (*root)->item) < 0)
	{
		if (node->left)
			btree_insert(&node->left, item, cmpf);
		else
			node->left = create_node(item);
	}
	else
	{
		if (node->right)
			btree_insert(&node->right, item, cmpf);
		else
			node->right = create_node(item);
	}
}
