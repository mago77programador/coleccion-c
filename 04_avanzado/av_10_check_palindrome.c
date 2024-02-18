#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_palindrome(const char *phrase, unsigned length);

int main(void)
{
    char *phrase1 = {"Hello, Dolly!"};
    char *phrase2 = {"Murder for a jar of red rum."};

    unsigned n1 = strlen(phrase1) - 1;
    unsigned n2 = strlen(phrase2) - 1;

    if (is_palindrome(phrase1, n1))
        printf("Sentence '%s' is palindrome\n", phrase1);
    else
        printf("Sentence '%s' is NOT palindrome\n", phrase1);

    if (is_palindrome(phrase2, n2))
        printf("Sentence '%s' is palindrome\n", phrase2);
    else
        printf("Sentence '%s' is NOT palindrome\n", phrase2);
}

bool is_palindrome(const char *phrase, unsigned length)
{
    // ¡¡¡Recuerda, son punteros!!!
    const char *s = phrase + 0;
    const char *e = phrase + length - 1;

    while (s < e)
    {
        if (!isalnum(*s))
        {
            s++;
        }
        else if (!isalnum(*e))
        {
            e--;
        }
        else if (toupper(*s) == toupper(*e))
        {
            s++;
            e--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
