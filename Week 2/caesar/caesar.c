#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int check_argument(int argc, string argv[]);
string encrypt(int key);

int main(int argc, string argv[])
{

    int key = check_argument(argc, argv);
    string ciphertext = encrypt(key);

    printf("ciphertext: %s\n", ciphertext);
}

int check_argument(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        exit(1);
    }

    string argument = argv[1];
    for (int i = 0; argument[i] != '\0'; i++)
    {
        if (!isdigit(argument[i]))
        {
            printf("Usage: ./caesar key\n");
            exit(1);
        }
    }

    int key = atoi(argv[1]);
    return key;
}

string encrypt(int key)
{
    string text = get_string("plaintext: ");

    string ciphertext = text;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (islower(text[i]))
        {
            ciphertext[i] = ((((text[i] - 'a') + key) % 26) + 'a');
        }
        if (isupper(text[i]))
        {
            ciphertext[i] = ((((text[i] - 'A') + key) % 26) + 'A');
        }
    }
    return ciphertext;
}
