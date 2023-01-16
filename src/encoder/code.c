#include "encoder.h"

int	len_string(char **dictionary, unsigned char *text)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (text[i] != '\0')
	{
		size += strlen(dictionary[text[i]]);
		i++;
	}
	return (size + 1);
}

char	*encode(char **dictionary, unsigned char *text)
{
	char    *code;
	int     size;

	size = len_string(dictionary, text);
	code = calloc(size, sizeof(char));
	for (int i = 0; text[i] != '\0'; i++)
		strcat(code, dictionary[text[i]]);
	return (code);
}

char	*decode(char *text, node_t *tree)
{
	int		i;
	node_t	*aux;
	char	*decode;
	char	temp[2];

	i = 0;
	aux = tree;
	decode = calloc(strlen(text), sizeof(char));
	while (text[i] != '\0')
	{
		if (text[i] == '0')
			aux = aux->left;
		else
			aux = aux->right;
		if (!aux->left && !aux->right)
		{
			temp[0] = aux->c;
			temp[1] = '\0';
			strcat(decode, temp);
			aux = tree;
		}
		i++;
	}
	free(aux);
	return (decode);
}
