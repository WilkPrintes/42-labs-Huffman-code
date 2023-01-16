#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <fcntl.h>

#define SIZE 256

typedef struct node
{
    unsigned char c;
    unsigned int freq;
    struct node *left;
    struct node *right;
    struct node *next;
} node_t;

typedef struct list
{
    node_t *first;
    int size;
} list_t;

void init_table(unsigned int table[], unsigned char text[]);
void insert_table(unsigned int table[], unsigned char text[]);
void print_table(unsigned int table[]);
void create_list(unsigned int table[], list_t *list);
void insert_sorted(list_t *list, node_t *node);
void fill_list(unsigned int table[], list_t *list);
void print_list(list_t *list);
void free_dictionary(char **dictionary);
void print_tree(node_t *node, int size);
void print_dictionary(char **dictionary);
void read_file(unsigned char *text, char *path);
char **alloc_dictionary(int colls);
char **create_dictionary(node_t *tree);
char *encode(char **dictionary, unsigned char *text);
char *decode(char *text, node_t *tree);
long file_size(char *path);
int len_string(char **dictionary, unsigned char *text);
int tree_height(node_t *tree);
node_t *remove_first(list_t *list);
node_t *create_tree(list_t *list);
