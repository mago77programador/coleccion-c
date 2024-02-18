/*
    This program prompts the user for the path to the text file and count the number
    of times each word appears in the file. It ignores upper and lowercase, punctuation
    marks, and plural forms.
    The final feature: print in reverse order of ocurrences and alphabetical order of
    words that have the same frequency.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000

typedef struct word_dict
{
    char word_st[50];
    int count_st;
}
word_dict;

int main()
{
    FILE *fptr;
    // Storage for file name
    char path[100];
    int i, len, index, is_unique;

    // Dictionary of words and ocurrences
    word_dict my_dict[MAX_WORDS];

    // Storage for individual words
    char word[50];

    // Input file path 
    printf("Enter file path: ");
    scanf("%s", path);

    // Try to open file
    fptr = fopen(path, "r");

    // Exit if file not opened successfully
    if (fptr == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check you have read previleges.\n");

        exit(EXIT_FAILURE);
    }

    // Initialize words count every field count_st to 0
    for (i = 0; i < MAX_WORDS; i++)
    {
        my_dict[i].count_st = 0;
    }        

    // This line initializes the index variable to 0
    index = 0;
    
    while (fscanf(fptr, "%s", word) != EOF)
    {
        // Convert word to lowercase
        strlwr(word);
        
        len = strlen(word);

        // Remove plural forms of candidate words
        if (len > 4)
        {
            // Remove apostrophe + s
            if (word[len - 1] == 's' && word[len - 2] == '\'')
            {
                word[len - 2] = '\0';
            }
            
            // Remove s + punctuation mark
            if (!isalnum(word[len - 1]) && word[len - 2] == 's')
            {
                word[len - 2] = '\0';
            }     

            // Remove last 's'
            if (word[len - 1] == 's')
            {
                word[len - 1] = '\0';
            }
        }   

        // Remove last punctuation character
        if (!isalnum(word[len - 1]))
        {
            word[len - 1] = '\0';
        }
           
        // Remove quotation marks between the end of a word and a punctuation mark    
        if (word[len - 2] == '\"')
        {
            word[len - 2] = '\0';
        }

        // Remove first punctuation character and annoying quotation marks
        if (!isalnum(word[0]) || word[0] == '\"')
        {
            // Shift each character in the "word" string one position to the left,
            // effectively removing the first character (remember... pointers)
            memmove(word, word + 1, strlen(word));
        }            
        
        // Check if word exits in all fields "word_st"
        is_unique = 1;
        for (i = 0; i < index && is_unique; i++)
        {
            if (strcmp(my_dict[i].word_st, word) == 0)
            {
                is_unique = 0;
            }                
        }

        // If word is unique then add it to array "my_dict" and increment
        // index. Otherwise increment occurrence count of current word.
        if (is_unique) 
        {
            strcpy(my_dict[index].word_st, word);
            my_dict[index].count_st++;

            index++;
        }
        else
        {
            // Why i - 1 ? To reverse the "i++" on line 110 and make sure
            // to increase the counter of the correct word
            my_dict[i - 1].count_st++;
        }
    }

    // Close file
    fclose(fptr);

    // Bubble sort algorithm: first sort by ocurrences
    int length = sizeof(my_dict) / sizeof(my_dict[0]);
    word_dict temp;

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (my_dict[j].count_st < my_dict[j + 1].count_st)
            {
                temp = my_dict[j];
                my_dict[j] = my_dict[j + 1];
                my_dict[j + 1] = temp;
            }

            // Second: alphabetical order of words that have the same frequency
            if (my_dict[j].count_st == my_dict[j + 1].count_st &&
                        strcmp(my_dict[j].word_st, my_dict[j + 1].word_st) > 0)
            {
                temp = my_dict[j];
                my_dict[j] = my_dict[j + 1];
                my_dict[j + 1] = temp;
            }
        }
    }

    // Print occurrences of all words in file
    printf("\nOccurrences of all distinct words in file: \n");
    for (i = 0; i < index; i++)
    {
        // %-15s prints string in 15 character width. - is used to print
        // string left align inside 15 character width space.
        printf("%-15s => %d\n", my_dict[i].word_st, my_dict[i].count_st);
    }    
    
    return 0;
}