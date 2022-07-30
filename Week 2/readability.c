#include <math.h>
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int i = 0;

    float index = (0.0588 * letters / words * 100) - (0.296 * sentences / words * 100) - 15.8;

    i = round(index);

    if (i < 2)
    {
        printf("Before Grade 1\n");
    }
    else if (i > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", i);
    }
}

int count_letters(string text)
{
    int count = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] >= 65 && text[i] <= 90)
        {
            count++;
        }
        else if (text[i] >= 97 && text[i] <= 122)
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 0;

    for (int i =  0, len = strlen(text); i <= len; i++)
    {
        if (text[i] == 32 || text[i] == 0)
        {
            count++;
        }
    }
    return count;
}

int count_sentences(string text)
{
    int count   = 0;

    for (int i =  0, len = strlen(text); i < len; i++)
    {
        if (text[i] == 33 || text[i] == 63 || text[i] == 46)
        {
            count++;
        }
    }
    return count;
}