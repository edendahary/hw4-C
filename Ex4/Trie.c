#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trie.h"
#include <ctype.h>

void init_node(node* node, char letter)
{
    int i;

    node->letter = letter;
    node->count = 0;
    
    for(i = 0; i < NUM_LETTERS; i++)
    {
        node->children[i] = NULL;
    }
}

void init_tree(tree* tree)
{
    tree->root = (node*)malloc(sizeof(node));
    init_node(tree->root, -1);
}

void add_word_to_tree(tree* tree, char* word)
{
    int i, j;
    node *curNode, *newNode;
    char curLetter;
    curNode = tree->root;

    for(i = 0; i < strlen(word); i++)
    {
        curLetter = tolower(word[i]);

        if(curNode->children[curLetter - 'a'] != NULL) // letter node exists in children array
        {
            curNode = curNode->children[curLetter - 'a'];
        }
        else
        {
            for(j = i; j < strlen(word); j++)
            {
                curLetter = tolower(word[j]);
                newNode = (node*)malloc(sizeof(node));
                init_node(newNode, curLetter);
                curNode->children[curLetter - 'a'] = newNode;
                curNode = newNode;
            }
            break;
        }     
    }
    curNode->count++;
}

void Print_Tree(tree* treez, int reversed_flag){
    char* str = malloc(1);
    int str_len = 0;

    Print_TreeRec(treez->root,str, reversed_flag, 0, &str_len);

    free(str);
    
}

void Print_TreeRec(node* treez,char str[], int reversed_flag, int i, int* str_length){
    if(treez == NULL)
    {
        return;
    }  
    else
    {  
        if(treez->letter != -1)
        {
            if(i >= *str_length)
            {
                str = realloc(str, *str_length + 1 + 1);
                (*str_length)++;
            }
            
            str[i]=treez->letter;
            str[i + 1] = '\0';

            if(treez->count > 0)
            {
                printf("%s , %d\n",str,treez->count);
            }

            ++i;
        }

        if(reversed_flag)
        {
            for(int j = NUM_LETTERS - 1; j >= 0; j--)
            {
                Print_TreeRec(treez->children[j], str, reversed_flag, i, str_length); 
            }
        }
        else
        {
            for(int j = 0; j < NUM_LETTERS; j++)
            {
              Print_TreeRec(treez->children[j], str, reversed_flag, i, str_length); 
            }
        }
        

    }
}
void freeTree(tree* trie)
{
    node* node = trie->root;
    
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        if (node->children[i] != NULL)
        {
            free(node->children[i]);
        }
    }
}






