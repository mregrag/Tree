/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:05:44 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/03 22:23:26 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	*btree_search(t_btree *root, void *data_ref, int (*cmpf)(void*, void*))
{
	void	*node;

	if (root)
	{
		if (!cmpf(root->item, data_ref))
			return (root->item);
		node = btree_search(root->left, data_ref, cmpf);
		if (node)
			return (node);
		node = btree_search(root->right, data_ref, cmpf);
		if (node)
			return (node);
	}
	return (NULL);
}
