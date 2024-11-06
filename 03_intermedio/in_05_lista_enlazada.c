#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

void clean_stdin(void);
void print_linked_list(node *head);
int is_positive_integer(const char *str);

int main(void)
{
    node *head = NULL, *tail = NULL;
    char answer = 'y';
    char input[100];

    while (answer == 'y' || answer == 'Y')
    {
        printf("Please, enter a positive integer: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (is_positive_integer(input))
        {
            int figure = atoi(input);
            printf("You entered: %d\n", figure);

            node *n = malloc(sizeof(node));
            if (n == NULL)
            {
                printf("Memory allocation failed\n");
                return 1;
            }
            n->number = figure;
            n->next = NULL;

            if (head == NULL)
            {
                head = tail = n;
            }
            else
            {
                tail->next = n;
                tail = n;
            }

            printf("Will you need to introduce more nodes? (y/n) ");
            scanf(" %c", &answer);
            clean_stdin();

            if (answer == 'n' || answer == 'N')
            {
                printf("Ok. Here is your list:\n");
                print_linked_list(head);

                // Free Willy, ouch!, nodes
                node *temp = head;
                while (temp != NULL)
                {
                    node *next = temp->next;
                    free(temp);
                    temp = next;
                }
                return 0;
            }
            else if (answer != 'y' && answer != 'Y')
            {
                printf("Invalid input.\n");

                // Free all nodes
                node *temp = head;
                while (temp != NULL)
                {
                    node *next = temp->next;
                    free(temp);
                    temp = next;
                }
                return 1;
            }
        }
    }
}

void clean_stdin(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void print_linked_list(node *head)
{
    for (node *current = head; current != NULL; current = current->next)
    {
        printf("%i\n", current->number);
    }
}

int is_positive_integer(const char *str)
{
    if (*str == '\0') return 0;
    while (*str)
    {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}
