#include "encoder.h"

void	sharing_memory(char **dictionary, char *code)
{
	char	*s_dictionary;
	char	*s_code;
	int		*s_size;
	int		shmid_dictionary;
	int		shmid_code;
	int		shmid_size;
	char	*dictionary_all;
	char	aux[2];

	dictionary_all = strdup("");
	shmid_dictionary = shmget(ftok("./encoder", 'D'), sizeof (char) * SIZE, 0666 | IPC_CREAT);
	shmid_size = shmget(ftok("./encoder", 'S'), sizeof (int), 0666 | IPC_CREAT);
	s_size = shmat(shmid_size, NULL, 0);
	s_size[0] = strlen(code);
	shmid_code = shmget(ftok("./encoder", 'C'), sizeof (char) * s_size[0], 0666 | IPC_CREAT);
	for (int i = 0; i < SIZE; i++)
	{
		if (dictionary[i][0] != '\0')
		{
			aux[0] = i;
			aux[1] = '\0';
			strcat(dictionary_all, aux);
			strcat(dictionary_all, dictionary[i]);
			strcat(dictionary_all, "\a");
		}
	}
	s_dictionary = shmat(shmid_dictionary, NULL, 0);
	s_code = shmat(shmid_code, NULL, 0);
	strcpy(s_code, code);
	strcpy(s_dictionary, dictionary_all);
} 

void	free_tree(node_t *tree)
{
	if (tree == NULL)
		return;
	free_tree(tree->left);
	free_tree(tree->right);
	free(tree);
}

int	main(int argc, char **argv)
{
	unsigned char	*text;
	unsigned int	freq_table[SIZE];
	list_t			list;
	node_t			*tree;
	char			**dictionary;
	char			*code;
	
	if (argc < 2 || open(argv[1], O_RDONLY) == -1)
	{
		printf("Por favor, insira um arquivo texto para compresão\n");
		return (1);
	}
	text = calloc(file_size(argv[1]) + 2, sizeof(char));
	read_file(text, argv[1]);
	init_table(freq_table, text);
	create_list(freq_table, &list);
	tree = create_tree(&list);
	dictionary = create_dictionary(tree);
	code = encode(dictionary, text);
	sharing_memory(dictionary, code);
	free(text);
	free(code);
	for (int i = 0; i < SIZE; i++)
		if (dictionary[i][0] != '\0')
			free(dictionary[i]);
	free(dictionary);	
	free_tree(tree);
	return (0);
}
