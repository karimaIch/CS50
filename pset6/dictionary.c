/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
#include "dictionary.h"

typedef struct node
{
    char word[LENGTH+1];
    struct node* next;
}  
node; 

node* hash_table[26]; 
int  dict_size=0;

int hash_function(char* key)
{
    return tolower(key[0]) - 'a';
}
/**
 * Returns true if word is in dictionary else false.
 * i'm here !
 */
bool check(const char* word)
{
    char mot_tmp[LENGTH+1];
    strcpy(mot_tmp, word);  
    int hash_value = hash_function(mot_tmp);

    for(int i = 0, size = strlen(mot_tmp); i < size; i++) // Design OK, Style OK
    {
            mot_tmp[i] = tolower(mot_tmp[i]); // we lowercase everything
    }
  
    if(hash_table[hash_value] == NULL)
    {
        return false;
    }
    else
    {
        node* p = hash_table[hash_value];
    	while(p != NULL)
    	{
        	if(!strcmp(p->word,mot_tmp))
            	return true;
        	else 
            	p = p->next;
        }
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 * On gros: on a un tableau qui va de 'a' à 'z' chaque element de ce tableau (chaque case) et un pointeur vers une liste de mot qui commence avec la lettre correspandante             
 * exemple hash_table['a'] et un pointeur vers une listes des mots qui commence avec 'a'
 *              hash_table['y'] et un pointeur vers une listes des mots qui commence avec 'y'. c'est ça ?
 */
bool load(const char* dictionary)
{
    // On ouvre le fichier dictionnaire
    FILE *dict = fopen(dictionary,"r");
    if (dict == NULL)
    {
         return false;
    }
  
    // declaration du mot a lire et de sa hash_value
    int hash_value = 0;
  	char dict_mot[LENGTH+1];
  
    // on itere through the file and get mot par mot
    while (fscanf(dict, "%s\n", dict_mot) != EOF)
    {
         // on crée un noeud pour notre mot et  on copie le nouveau nom
        node* new_node = malloc(sizeof(node));
        strcpy(new_node->word, dict_mot);
        
        // on calcule la hash_value du nom
        hash_value = hash_function(dict_mot);
     
  		// pour ne pas risquer de manipuler des pointeurs, on va pas utiliser l'insertion ici meme
      	// le principe c'est qu'on va inserer en tete de liste, du coup une case dans tableau hash_table pointe toujours sur le dernier element inserer
      	// si la case du hash_table est un pointeur null, ça veut dire qu'on a pas encore inserer de mot dans cette liste
      	// on rappelle que chaque case est un pointeur vers une liste de mots
        if(hash_table[hash_value] == NULL)
        {
   			hash_table[hash_value] = new_node;
			new_node->next = NULL;
		}
     	else 
   		{
    		new_node->next = hash_table[hash_value];
    		hash_table[hash_value] = new_node;
   		}
        dict_size++; 

    }
    fclose(dict);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not ypset loaded.
 */
unsigned int size(void)
{
    return dict_size;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
  	// on boucle sur le tableau des pointeurs
    for(int i=0; i<26; i++)
    {
      	// on boucle sur chaque liste est on libere les noeuds
        while(hash_table[i] != NULL)
        {
            node* tmp = hash_table[i];
            hash_table[i] = hash_table[i]->next;
            free(tmp);        
        } 
    }
    //printf("unload success\n");
    return true;
}
