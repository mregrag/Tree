/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:11:19 by mregrag           #+#    #+#             */
/*   Updated: 2024/09/03 22:55:51 by mregrag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_H
# define BTREE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;

}	t_btree;

t_btree	*create_node(void *item);
t_btree	*btree_delete_node(t_btree *root, void *item, int (*cmpf)(void *, void *));
void	btree_apply_preorder(t_btree *root, void (*applyf)(void *));
void	btree_apply_inorder(t_btree *root, void (*applyf)(void *));
void	btree_apply_postorder(t_btree *root, void (*applyf)(void *));
void	*btree_search(t_btree *root, void *data_ref, int (*cmpf)(void*, void*));
void	btree_insert(t_btree **root, void *item, int (*cmpf)(void *, void *));
int		btree_count_level(t_btree *root);

#endif
