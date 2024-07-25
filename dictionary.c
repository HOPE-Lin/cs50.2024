// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 500;
int number = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    node* p = NULL;
    int i = hash(word);
    p = table[i];
    while (p != NULL)
    {
        if (strcasecmp(word, p->word) == 0)
        {
            return true;
        }
        p = p->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int j = 0;
    for (int i = 0; word[i] != '\0';i++)
    {
        j += (tolower(word[i] - 'a') * i * 37) % 500;
    }
    return j;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE* source = fopen(dictionary, "r");
    int i = 0;
    if (source == NULL)
    {
        return false;
    }
    char buffer[46];
    node * newnode;
    while (fscanf(source, "%s", buffer) != EOF)
    {
        newnode = malloc(sizeof(node));
        i = hash(buffer);
        if (newnode == NULL)
        {
            return false;
        }
        newnode->next = table[i];
        table[i] = newnode;
        strcpy(newnode->word, buffer);
        number++;
    }
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return number;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODD
    for(int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            node *p = table[i];
            node *q = p;
            while (q != NULL)
            {
                q = q->next;
                free(p);
                p = q;
            }
        }
        table[i] = NULL;
    }
    return true;
}
