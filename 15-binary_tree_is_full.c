#include "binary_trees.h"

int binary_tree_is_full(const binary_tree_t *tree)
{
	int l, r;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left && tree->right)
	{
		l = binary_tree_is_full(tree->left);
		r = binary_tree_is_full(tree->right);
		return (l * r);
	}
	return (0);

}
