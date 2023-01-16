#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <string.h>

typedef struct node
{
    unsigned char c;
    unsigned int freq;
    struct node *left;
    struct node *right;
    struct node *next;
} node_t;

typedef struct table
{
    unsigned char c;
    char *code;
} table_t;
