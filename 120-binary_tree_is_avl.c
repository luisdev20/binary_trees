#include "binary_trees.h"

/**
 * array_to_bst - insert a new node in a Binary Search Tree
 * @array: arrya to use
 * @size: array size
 *
 * Return: If no common ancestor was found return NULL
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    unsigned int z;
    if (binary_tree_is_bst(tree) != 0 && binary_tree_is_perfect(tree) != 0)
        return (1);
    else
        return (0);
}

/**
 * binary_tree_is_bst - finds the lowest common ancestor of two nodes
 * @tree: a pointer to the first node
 *
 * Return: If no common ancestor was found return NULL
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    if (less(tree->left, tree->n) && greater(tree->right, tree->n))
    {
        if (!tree->left || binary_tree_is_bst(tree->left))
        {
            if (!tree->right || binary_tree_is_bst(tree->right))
            {
                return (1);
            }
        }
    }
    return (0);
}

/**
 * less - verify is node value is less root value
 * @tree: a pointer to the first node
 * @n: root value
 * Return: return 1 if are right or 0 if failes
 */
int less(const binary_tree_t *tree, int n)
{
    int left, right;

    if (tree == NULL)
        return (1);
    if (tree->n < n)
    {
        left = less(tree->left, n);
        right = less(tree->right, n);
        if (left != 0 && right != 0)
        {
            return (1);
        }
    }
    return (0);
}

/**
 * greater - verify is node value is greater root value
 * @tree: a pointer to the first node
 * @n: root value
 * Return: return 1 if are right or 0 if failes
 */
int greater(const binary_tree_t *tree, int n)
{
    int left, right;

    if (tree == NULL)
        return (1);

    if (tree->n > n)
    {
        left = greater(tree->left, n);
        right = greater(tree->right, n);
        if (left != 0 && right != 0)
        {
            return (1);
        }
    }
    return (0);
}

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: If tree is NULL, your function must return 0, else return the depth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree || !tree->parent)
		return (count);

	count = 1 + binary_tree_depth(tree->parent);

	return (count);
}

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree.
 * @tree: A pointer to the root node of the tree to count the number of nodes.
 *
 * Return: If tree is NULL, the function must return 0, else return node count.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	count += 1;
	count += binary_tree_nodes(tree->left);
	count += binary_tree_nodes(tree->right);

	return (count);

}

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or is not full - 0.
 *         Otherwise - 1.
 */
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

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or not perfect, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int l, r;

	if (!tree)
		return (0);

	if (binary_tree_is_full(tree) == 0)
		return (0);

	if (binary_tree_depth(tree->left) == binary_tree_depth(tree->right))
	{
		l = binary_tree_nodes(tree->left);
		r = binary_tree_nodes(tree->right);
		if ((l + r) < 3)
			return (1);
	}

	return (0);

}
