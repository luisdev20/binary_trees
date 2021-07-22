#include "binary_trees.h"

bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	if (value == tree->n)
		return (bst_t *)tree;

	if (value < tree->n)
		return bst_search(tree->left, value);
	else
		return bst_search(tree->right, value);

}
