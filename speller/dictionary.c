// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
int number = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    node* p;
    int i = tolower(word[0]) - 'a';
    do
    {
        p = table[i];
        if (strcasecmp(word, p->word) == 0)
        {
            return true;
        }
        p = p->next;
    }
    while (p != NULL)
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *source = fopen(dictionary, "r");
    int i = 0;
    if (source == NULL)
    {
        return false;
    }
    char buffer[46];
    while (fscanf(source, "%s", buffer) != EOF)
    {
        node* newnode = malloc(sizeof(node));
        i = buffer[0] - 'a';
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
    for(int i = 0; i < 26; i++)
    {
        if (table[i] != NULL)
        {
            node *p = table[i];
            node *q = p;
            while (q == NULL)
            {
                q = q->next;
                free(p);
                p = p->next;
            }
        }
    }
    return false;
}
