#include "decoder.h"

char    *ft_strjoin(char *str1, char *str2)
{
    size_t    len1;
    size_t    len2;
    char    *ret;

    len1 = strlen(str1);
    len2 = strlen(str2);
    ret = calloc(len1 + len2 + 1, sizeof(char));
    strcpy(ret, str1);
    strcpy(&ret[len1], str2);
    return (ret);
}

void unzip(table_t **table, char *code, int tam)
{
    int index;
    int i;
    char *buffer;
    char aux[2];
    int size;

    index = 1;
    aux[0] = code[0];
    aux[1] = '\0';
    buffer = strdup(aux);
    size = strlen(code);
    while (size >= 0)
    {
        for (i = 0; i < tam; i++)
        {
            if (strcmp(table[i]->code, buffer) == 0)
            {
                printf("%c", table[i]->c);
                buffer = strdup("");
                break;
            }
        }
        aux[0] = code[index];
        strcat(buffer, aux);
        index++;
        size--;
    }
    free(buffer);
    printf("\n");
}

int main (void)
{
	int shmid_dictionary;
    int shmid_code;
    int shmid_size;
    char *shered_code;
    char *shered_dictionary;
    int *size;
    table_t **table;
    table_t *aux;
    char auxbuff[2];
    char *buffer;
    int index;
    
    index = 0;
    buffer = calloc(9, sizeof(char));
    table = malloc(sizeof(table_t) * 256);
    shmid_dictionary = shmget(ftok("./encoder", 'D'), sizeof (char) * 256, 0666 | IPC_CREAT);
    shmid_size = shmget(ftok("./encoder", 'S'), sizeof (int), 0666 | IPC_CREAT);
    shered_dictionary = shmat(shmid_dictionary, NULL, 0);
    size = shmat(shmid_size, NULL, 0);
    shmid_code = shmget(ftok("./encoder", 'C'), sizeof (char) * size[0], 0666 | IPC_CREAT);
    shered_code = shmat(shmid_code, NULL, 0);
    for (int i = 0; i < (int) strlen(shered_dictionary); i++)
    {
        if (shered_dictionary[i] != '\a')
        {
            aux = malloc(sizeof(table_t));
            aux->c = shered_dictionary[i];
            i++;
            buffer = strdup("");
            while (shered_dictionary[i] != '\a')
            {
                auxbuff[0] = shered_dictionary[i];
                auxbuff[1] = '\0';
                buffer = ft_strjoin(buffer, auxbuff);
                i++;
            }
            aux->code = strdup(buffer);
            table[index] = aux;
            free(buffer);
            index++;
        }
    }
    unzip(table, shered_code, index);
    free(buffer);
    for (int i = 0; i < index; i++)
    {
        free(table[i]->code);
        free(table[i]);
    }
    free(table);
    shmctl(shmid_dictionary, IPC_RMID, NULL);
    shmctl(shmid_code, IPC_RMID, NULL);
    shmctl(shmid_size, IPC_RMID, NULL);
    return (0);
}