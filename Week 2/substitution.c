#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

//Declaração da função
string substitution(string word, string key);
int check(string key);

//Main com parametro
int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./substitution key \n");
        return 1;
    }

    else if (strlen(argv[1]) != 26)
    {
        printf("Key is not valid. \n");
        return 1;
    }
    else if(argc == 2)
    {
        string plaintext = get_string("plaintext: ");

        string cyphertext = substitution(plaintext, argv[1]);

        printf("ciphertext: %s", cyphertext);
    }
    printf("\n");
}

string substitution(string word, string key)
{

    //Variavel para substituição
    string sub = word;

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            sub[i] = toupper (key[word[i] - 'A']);
        }
        else if (islower(word[i]))
        {
            sub[i] = tolower (key[word[i] - 'a']);
        }
    }

    //resultado
    return sub;
}

int check(string key)
{
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        if (key[i] < 'a' || key[i] > 'z' || key[i] < 'A' || key[i] > 'Z')
        {
            return 1;
        }
    }
    return 0;
}