#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)//Make sure program was run with just one command-line argument
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int k = 0; k < strlen(argv[1]); k++)
    {
        if (isalpha(argv[1][k]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int k = atoi(argv[1]) % 26;//convert argv from a string to an int
    string pltxt = get_string("plaintext: ");//take plaintext from user
    printf("ciphertext: ");

    for (int i = 0; i < strlen(pltxt); i++)//rotate the character
    {
        if (!isalpha(pltxt[i]))
        {
            printf("%c", pltxt[i]);
            continue;
        }
        int ascii_offset = isupper(pltxt[i]) ? 65 : 97;
        int pi = pltxt[i] - ascii_offset;
        int ci = (pi + k) % 26;//using formula
        printf("%c", ci + ascii_offset);
    }
    printf("\n");
    return 0;
}
