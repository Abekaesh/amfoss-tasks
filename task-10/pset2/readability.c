#include <ctype.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

//Declaring functions
int count_words(string a);
int count_sentence(string b);
int count_letters(string c);

int main(void)
{
    string text = get_string("Text: ");
    //calling functions
    int w = count_words(text) + 1;
    int se = count_sentence(text);
    int le = count_letters(text);
    // number of letters in 100 words
    float L = (le * 100.0) / w ;
    // number of sentences in 100 words
    float S = (se * 100.0) / w ;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Output generation
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}

// Function to count words
int count_words(string a)
{
    int words = 0;
    for (int i = 0, n = strlen(a); i < n; i++)
    {
        if (isspace(a[i]))
        {
            words += 1;
        }
    }
    return words;

}

//Function to count sentences
int count_sentence(string b)
{
    int sentence = 0;
    for (int i = 0, n = strlen(b); i < n; i++)
    {
        if ((b[i] == '.') || (b[i] == '!') || (b[i] == '?'))
        {
            sentence += 1;
        }
    }
    return sentence;
}
