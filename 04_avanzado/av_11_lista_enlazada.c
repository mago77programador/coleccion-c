#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIST_SIZE 4
#define MAX_LENGTH 60

typedef struct node
{
    char phrase[MAX_LENGTH];
    struct node *next;
}
node;

void unload(node *list);
void visualize(node *list);
void clean_stdin(void);

int main(void)
{
    // First step: a head of the list
    node *list = NULL;

    // Add items to list
    for (int i = 0; i < LIST_SIZE; i++)
    {
        char phrase[MAX_LENGTH];
        printf("Enter a new phrase: ");
        scanf(" %[^\n]", phrase);
        clean_stdin();

        // Add phrase to new node in list
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Couldn't allocate memory for node\n");
            return 1;
        }
        strcpy(n->phrase, phrase);
        n->next = list;

        list = n;

        // Visualize list after adding a node.
        visualize(list);
    }

    unload(list);
}

void unload(node *list)
{
    // Free all allocated nodes
    while (list != NULL)
    {
        node *ptr = list->next;
        free(list);
        list = ptr;
    }
}

void visualize(node *list)
{              
    printf("\n|-_-_ List Visualizer _-_-|\n\n");
    while (list != NULL)
    {
        printf("Location %p\n", list);
        printf("Phrase: \"%s\"\n", list->phrase);
        printf("Next: %p\n\n", list->next);
        list = list->next;
    }
    printf("|-_-_^^^^vvvvvvvvv^^^^_-_-|\n\n");
}

void clean_stdin(void)
{
    int c;
    do
    {
        c = getchar();
    }
    while (c != '\n' && c != EOF);
}