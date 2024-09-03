/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_delete_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:34:52 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/03 22:55:01 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

t_btree	*find_min(t_btree *node)
{
	t_btree	*current;

	current = node;
	while (current && current->left != NULL)
		current = current->left;
	return (current);
}

t_btree	*btree_delete_node(t_btree *root, void *item, int (*cmpf)(void *, void *))
{
	t_btree	*temp;

	if (root == NULL)
		return (root);
	if (cmpf(item, root->item) < 0)
		root->left = btree_delete_node(root->left, item, cmpf);
	else if (cmpf(item, root->item) > 0)
		root->right = btree_delete_node(root->right, item, cmpf);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		temp = find_min(root->right);
		root->item = temp->item;
		root->right = btree_delete_node(root->right, temp->item, cmpf);
	}
	return (root);
}
