#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trie.h"
int main(int argc, char *argv[])
{
    if(argc > 2){
        printf("Eror");
        return 0;
    }
    if(argc == 2 && *argv[1]!= 'r'){
         printf("Eror");
        return 0;
    }
    int i = 0;
    char *str = (char *)malloc(sizeof(char)+2);
    char currLetter;
    tree* Trie= malloc(sizeof(node)) ;
    init_tree(Trie);
    while (scanf("%c", &currLetter) == 1 )
    {
        if((currLetter >='a' && currLetter <= 'z') || (currLetter >='A' && currLetter <= 'Z')){
        str[i] = currLetter;
        i++;
        str =realloc(str,sizeof(char)+2);
        }
      
        else if(currLetter == '\t' || currLetter == '\n' || currLetter == ' ' ) {
            add_word_to_tree(Trie, str);
            str = calloc(1,sizeof(char)+2);
            i=0;
        }
       
    }
    free(str);
if (argc != 2)
    {
        Print_Tree(Trie, 0);
    }
    else 
    {
        Print_Tree(Trie, 1);
    }
    
    freeTree(Trie);
    return 0;
}