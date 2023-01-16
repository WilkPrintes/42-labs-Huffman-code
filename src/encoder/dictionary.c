#include "encoder.h"

void    create(char **dictionary, node_t *tree, char *path, int colls);

char    **alloc_dictionary(int colls)
{
	char    **dictionary;

	dictionary = (char **)malloc(sizeof(char *) * SIZE);
	for (int i = 0; i < SIZE; i++)
		dictionary[i] = calloc(colls, sizeof(char));
	return (dictionary);
}

void    create(char **dictionary, node_t *tree, char *path, int colls)
{
	char    left[colls];
	char    right[colls];

	if (!tree->left && !tree->right)
	{
		strcpy(dictionary[tree->c], path);
		return;
	}
	strcpy(left, path);
	strcpy(right, path);
	strcat(left, "0");
	strcat(right, "1");
	create(dictionary, tree->left, left, colls);
	create(dictionary, tree->right, right, colls);
}

void    print_dictionary(char **dictionary)
{
	printf("\n\tDICIONÁRIO\n");
	for (int i = 0; i < SIZE; i++)
		if (dictionary[i][0] != '\0')
			printf("\t%c: %s\n", i, dictionary[i]);
}

char    **create_dictionary(node_t *tree)
{
	int     colls;
	char    **dictionary;
	
	colls = tree_height(tree) + 1;
	dictionary = alloc_dictionary(colls);
	create(dictionary, tree, "", colls);
	return (dictionary);
}