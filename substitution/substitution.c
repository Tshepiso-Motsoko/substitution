#include <cs50.h>     //Include CS50 library to use get_string() function
#include <ctype.h>    //Include ctype library to use isalpha(), isupper(), tolower() functions
#include <stdio.h>    //Include stdio library to use printf() function
#include <string.h>   //Include string library to use strlen() function

bool validate_key(string s);   //Function prototype for validate_key()

int main(int argc, string argv[])
{
    //Ensure the program is executed with exactly one command-line argument
    if (argc != 2 || !validate_key(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    //Convert the key to all lowercase for easy mapping
    for (int i = 0; i < 26; i++)
    {
        key[i] = tolower(key[i]);
    }

    //Prompt the user for the plaintext
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        //Check if the character is a letter
        if (isalpha(plaintext[i]))
        {
            //Preserve the case of the character and encrypt it using the key
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            printf("%c", ((plaintext[i] - base + key[plaintext[i] - base] - 'a') % 26) + base);
        }
        else
        {
            //Print non-alphabetical characters as is
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
    return 0;
}

bool validate_key(string s)
{
    int letters[26] = {0};

    //Check if the key has exactly 26 characters
    if (strlen(s) != 26)
    {
        return false;
    }

    for (int i = 0; i < 26; i++)
    {
        //Check if the character is a letter and appears exactly once in the key
        if (!isalpha(s[i]) || letters[tolower(s[i]) - 'a']++ > 0)
        {
            return false;
        }
    }

    return true;
}
