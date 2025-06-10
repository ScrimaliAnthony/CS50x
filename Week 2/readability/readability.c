#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float compute_L(int letters, int words);
float compute_S(int words, int sentences);
int compute_index(float L, float S);

int main(void)
{
    string text = get_string("sentence: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    float L = compute_L(letters, words);
    float S = compute_S(words, sentences);
    int index = compute_index(L, S);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index <= 15)
    {
        printf("Grade %i\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{
    int letters = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 0;
    int space = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            space++;
        }
    }
    words = space + 1;

    return words;
}

int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }

    return sentences;
}

float compute_L(int letters, int words)
{
    float L = ((float) letters / words) * 100;
    return L;
}

float compute_S(int words, int sentences)
{
    float S = ((float) sentences / words) * 100;
    return S;
}

int compute_index(float L, float S)
{
    float index = round(0.0588 * L - 0.296 * S - 15.8);
    return index;
}
