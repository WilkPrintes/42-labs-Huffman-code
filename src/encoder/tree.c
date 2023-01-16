#include "encoder.h"

node_t  *create_tree(list_t *list)
{
	node_t  *node;
	node_t  *left;
	node_t  *right;

	while (list->size > 1)
	{
		left = remove_first(list);
		right = remove_first(list);
		node = malloc(sizeof(node_t));
		node->c = 0;
		node->freq = left->freq + right->freq;
		node->left = left;
		node->right = right;
		node->next = NULL;
		insert_sorted(list, node);
	}
	return (list->first);
}

void	print_tree(node_t *node, int size)
{
	if (!node->left && !node->right)
		printf("\tFolha %c: Altura %u\n", node->c, size);
	else
	{
		print_tree(node->left, size + 1);
		print_tree(node->right, size + 1);
	}
}

int	tree_height(node_t *tree)
{
	int	left;
	int	right;

	if (!tree)
		return (-1);
	else
	{
		left = tree_height(tree->left);
		right = tree_height(tree->right);
		if (left > right)
			return (left + 1);
		else
			return (right + 1);
	}
}
