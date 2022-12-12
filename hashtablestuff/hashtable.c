#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#define MAXWORDSIZE 45 //max length of a word


#define N 676 // number of buckets in hashtable
int COUNT = 0;

// Represents a node in a hash table
struct node
{
    char word[MAXWORDSIZE + 1];
    struct node * next;
};

typedef struct node * nodeaddress;

bool search(const char *word);
unsigned int hash(const char *word);
void load(const char *dictionary);
unsigned int size(void);
void unload(void);


// The actual hash table
nodeaddress table[N];


// checks if word is in hash table
bool search(const char *word)
{
    int hashkey = hash(word);
    const char *shabd = word;

    for (nodeaddress tmp = table[hashkey]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(tmp->word, shabd) == 0) 
        {
            return true;
        }
    }

    return false; // outside the for loop since we have to check the whole linked list of the particular hash table bucket


}

// Hashes word to a number
unsigned int hash(const char *word) // simple hash function. Words starting with 'aa' would map to bucket 0, 'ab' to bucket 1, 'ba' to 26, 'zz' to 675, etc
{
    //return word[0] - 97; //this is just for testing if 'a' then ascii of a is 97 so returns 0 so position of word starting with a is table[0]

    if (word[1] == '\0')
    {
        if (islower(word[0]))
        {
            return word[0] - 'a'; // like for the word "a"
        }
        else if (isupper(word[0]))
        {
            return word[0] - 'A'; // cause needs to be case-insensitive
        }

        else
        {
            return 0; 
        }
    }

    else if (isalpha(word[0]) && isalpha(word[1]) )
    {
        if (islower(word[0]) && islower(word[1]))
        {
            return ( (word[0] - 'a') * 26 + (word[1] - 'a') );  //'a' means 97
        }
        else if (isupper(word[0]) && islower(word[1]))
        {
            return ( (word[0] - 'A') * 26 + (word[1] - 'a') );
        }
        else if (islower(word[0]) && isupper(word[1]))
        {
            return ( (word[0] - 'a') * 26 + (word[1] - 'A') );
        }
        else if (isupper(word[0]) && isupper(word[1]))
        {
            return ( (word[0] - 'A') * 26 + (word[1] - 'A') );
        }

        else
        {
            return 0; 
        }

    }

    else if (word[0] == '\'') //apostrophe
    {
        if (islower(word[1]))
        {
            return word[1] - 'a'; // like for the word "a"
        }
        else if (isupper(word[1]))
        {
            return word[1] - 'A'; // cause needs to be case-insensitive
        }
        else
        {
            return 0; 
        }
    }

    else if (word[1] == '\'') //apostrophe
    {
        if (islower(word[0]))
        {
            return word[0] - 'a'; // like for the word "a"
        }
        else if (isupper(word[0]))
        {
            return word[0] - 'A'; // cause needs to be case-insensitive
        }
        else
        {
            return 0;
        }
    }

    else
    {
        return 0;
    }

}


// Loads the given dictionary of words into hash table
void load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r");

    char buffer[MAXWORDSIZE+1]; 

    while(fscanf(dict, "%s", buffer) != EOF)

    {
        nodeaddress n = malloc(sizeof(struct node));

        //copy the string in buffer into the word part of node and set the next pointer to NULL
        strcpy(n->word, buffer);
        n->next = NULL;
        // int hashkey = hash(n->word);

        if (table[hash(n->word)] == NULL) //if the location in the table does not have any node then just assign it the current node
                                          //so the current node becomes the first node in the linked list associated with that table location
        {
            table[hash(n->word)] = n;
            COUNT++;
        }

        /* if there is already a node at that location then insert the current node at the first position
            by assigning the next pointer of current node to the preexisting node then assigning table[hash()] to
            the current node

            Moreover, since we are looking at const time O(1) insertion each word gets inserted at the beginning and 'pushes' the previous word further down
            the linked list
        */

        else
        {
            n->next = table[hash(n->word)];
            table[hash(n->word)] = n;
            COUNT++;
        }

    }

    fclose(dict);
    return;

}

// number of words in dictionary 
unsigned int size(void)
{
    return COUNT;
}


// unloads/frees dictionary from memory to avoid memory leaks
void unload(void)
{
   for (int i = 0; i < N; i++)
    {

        while (table[i] != NULL)
        {
            nodeaddress temp = table[i]->next;
            free(table[i]);
            table[i] = temp;
        }

        if (table[i] == NULL && i == N - 1)
        {
            return;
        }
    }



}

// void printelements(nodeaddress table)
// {
//     for (int i = 0; i < N; i++)
//     {
//         nodeaddress temp = table[i];
//         while(temp->next != NULL)
//         {
//             printf(" %i ", temp->word);
//         }

//         printf("\n");
//     }

// }


int main(int argc, char *argv[])
{
    // Check for correct number of args
    if (argc != 2 && argc != 3)
    {
        printf("Please use as follows: ./hashtable [dictionary] [text]\n");
        return 1;
    }

    char * text = argv[2];
    char * dictionary = argv[1];

    FILE *file = fopen(text, "r");

    load(dictionary);

    printf("\n Misspelled words\n\n");

    int index = 0;
    int  misspellings = 0;
    int  words = 0;
    char word[MAXWORDSIZE + 1];

    // spellcheck words in given input
    char c;
    while (fread(&c, sizeof(char), 1, file))
    {
        if (isalpha(c) || (c == '\'' && index > 0)) //apostrophe is there after the backslash look closely
        {
            // make the word character by character
            word[index] = c;
            index++;

            // ignore words that are too big
            if (index > MAXWORDSIZE)
            {
                // Prepare for new word
                index = 0;
            }
        }

        // Ignore words with numbers
        else if (isdigit(c))
        {
            // Prepare for new word
            index = 0;
        }

        // We must have found a whole word
        else if (index > 0)
        {
            // End current word with null char
            word[index] = '\0';

            // Update counter
            words++;

            // Print word if wrong spelling and increment number of misspellings
            if (!search(word))
            {
                printf("%s\n", word);
                misspellings++;
            }
            // Prepare for next word
            index = 0;
        }
    }

    fclose(file);
    unsigned int n = size(); 
    unload(); // Unload dictionary
    

    printf("\nWords misspelled:    %d\n", misspellings);
    printf("Words in dictionary:   %d\n", n);
    printf("Words in the text:     %d\n", words);
    return 0;
}























