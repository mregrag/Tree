# Binary Tree Operations

This project implements a set of functions for creating and manipulating a binary tree data structure:

## Function Prototypes

```c
t_btree *create_node(void *item);
t_btree *btree_delete_node(t_btree *root, void *item, int (*cmpf)(void *, void *));
void btree_apply_preorder(t_btree *root, void(*applyf)(void *));
void btree_apply_inorder(t_btree *root, void (*applyf)(void *));
void btree_apply_postorder(t_btree *root, void (*applyf)(void *));
void *btree_search(t_btree *root, void *data_ref, int (*cmpf)(void*, void*));
void btree_insert(t_btree **root, void *item, int (*cmpf)(void *, void *));
int btree_count_level(t_btree *root);
```
## Functions

1. `create_node`
   * Creates a new node for the binary tree.
   * Parameters: `item` - The data to be stored in the new node.
   * Returns: A pointer to the newly created node.
    ```c
    t_btree	*create_node(void *item)
      {
      	t_btree	*node;
      
      	node = malloc(sizeof(t_btree));
      	if (!node)
      		return (NULL);
      	node->item = item;
      	node->left = NULL;
      	node->right = NULL;
      	return (node);
      }
    ```

2. `btree_delete_node`
   * Deletes a specific node from the binary tree.
   * Parameters:
      * `root`: The root of the tree.
      * `item`: The item to be deleted.
      * `cmpf`: A comparison function to locate the item.
   * Returns: The new root of the tree after deletion.
```c
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
```
3. `btree_apply_preorder`
   * Applies a given function to each node in pre-order traversal (root, left, right).
   * Parameters:
      * `root`: The root of the tree.
      * `applyf`: The function to apply to each node.
```c
void	btree_apply_preorder(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL)
		return ;
	applyf(root->item);
	if (root->left)
		btree_apply_preorder(root->left, applyf);
	if (root->right)
		btree_apply_preorder(root->right, applyf);
}
```
4. `btree_apply_inorder`
   * Applies a given function to each node in in-order traversal (left, root, right).
   * Parameters: Same as `btree_apply_preorder`.
```c
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
```
5. `btree_apply_postorder`
   * Applies a given function to each node in post-order traversal (left, right, root).
   * Parameters: Same as `btree_apply_preorder`.
```c
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
```

6. `btree_search`
   * Searches for a specific item in the binary tree.
   * Parameters:
      * `root`: The root of the tree.
      * `data_ref`: The item to search for.
      * `cmpf`: A comparison function to match items.
   * Returns: A pointer to the found item, or NULL if not found.
```c
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
```
7. `btree_insert`
   * Inserts a new item into the binary tree.
   * Parameters:
      * `root`: A pointer to the root of the tree.
      * `item`: The item to insert.
      * `cmpf`: A comparison function to determine the insertion position.
```c
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
```
8. `btree_count_level`
   * Counts the number of levels (height) in the binary tree.
   * Parameters: `root` - The root of the tree.
   * Returns: The height of the tree.
```c
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
```
## Usage

These functions provide a complete set of operations to create, manipulate, and traverse a binary tree. They can be used to implement various tree-based algorithms and data structures, such as binary search trees, expression trees, or decision trees.

The use of function pointers (`cmpf` and `applyf`) allows for flexible handling of different data types and custom operations on tree nodes.
```c
int	compare_strings(void *a, void *b)
{
	return strcmp((const char *)a, (const char *)b);
}

void	display(void *item)
{
	printf("%s\t", (char *) item);
}
```
