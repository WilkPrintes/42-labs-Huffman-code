#include "encoder.h"

void    init_table(unsigned int table[], unsigned char text[])
{
	int i;

	for (i = 0; i < SIZE; i++)
		table[i] = 0;
	insert_table(table, text);
}

void    insert_table(unsigned int table[], unsigned char text[])
{
	int i;

	for (i = 0; text[i] != '\0'; i++)
		table[text[i]]++;
}