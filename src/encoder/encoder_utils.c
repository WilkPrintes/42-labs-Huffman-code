#include "encoder.h"

long file_size(char *path)
{
	FILE *file;
	long size;

	file = fopen(path, "r");
	size = 0;
	if (!file)
		return (0);
	while(fgetc(file) != -1)
		size++;
	fclose(file);
	return (size);
}

void read_file(unsigned char *text, char *path)
{
	FILE *file;
	char c;
	int i;

	i = 0;
	file = fopen(path, "r");
	if (!file)
		return;
	while(!feof(file))
	{
		c = fgetc(file);
		if (c != -1)
			text[i++] = c;
	}
	fclose(file);
}
