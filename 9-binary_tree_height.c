#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree)
{
        size_t right_side = 0;
        size_t left_side = 0;

        if (tree == NULL || (tree->left == NULL && tree->right == NULL))
                return (0);

        left_side = 1 + binary_tree_height(tree->left);
        right_side = 1 + binary_tree_height(tree->right);

        if (left_side > right_side)
                return (left_side);
	return (right_side);
}
