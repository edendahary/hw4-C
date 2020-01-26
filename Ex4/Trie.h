#ifndef _TRIE_H
#define _TRIE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_LETTERS ((int)26)

typedef struct node
{ 
    char letter;
    int count;   
    struct node* children[NUM_LETTERS];
}node;

typedef struct tree {
    node* root;
} tree;

void init_node(node* node, char letter);
void init_tree(tree* tree);
void add_word_to_tree(tree* tree, char* word);
void Print_Tree(tree* treez, int reversed_flag);
void Print_TreeRec(node* treez,char str[], int reversed_flag, int i, int* str_length);
void freeTree(tree* trie);

#endif


