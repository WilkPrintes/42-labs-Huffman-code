#include "encoder.h"

void    create_list(unsigned int table[], list_t *list)
{
	list->first = NULL;
	list->size = 0;
	fill_list(table, list);
}

void    insert_sorted(list_t *list, node_t *node)
{
	node_t	*aux;

	if (list->first == NULL)
		list->first = node;
	else if (node->freq < list->first->freq)
	{
		node->next = list->first;
		list->first = node;
	}
	else
	{
		aux = list->first;
		while (aux->next != NULL && aux->next->freq < node->freq)
			aux = aux->next;
		node->next = aux->next;
		aux->next = node;
	}
	list->size++;
}

void	fill_list(unsigned int table[], list_t *list)
{
	node_t	*node;

	for (int i = 0; i < SIZE; i++)
	{
		if (table[i] != 0)
		{
			node = (node_t *)malloc(sizeof(node_t));
			node->c = i;
			node->freq = table[i];
			node->left = NULL;
			node->right = NULL;
			node->next = NULL;
			insert_sorted(list, node);
		}
	}
}

void	print_list(list_t *list)
{
	node_t	*aux;

	aux = list->first;
	printf("\tLISTA ORDANADA\n");
	while (aux != NULL)
	{
		printf("\t %c: %u\n", aux->c, aux->freq);
		aux = aux->next;
	}
}

node_t	*remove_first(list_t *list)
{
	node_t	*aux;

	aux = NULL;
	if (list->first)
	{
		aux = list->first;
		list->first = aux->next;
		aux->next = NULL;
		list->size--;
	}
	return (aux);
}