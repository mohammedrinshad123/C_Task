#include <stdio.h>
#include <ctype.h>
int main()
{
    char str[100];
    int vowels = 0, consonants = 0, digits = 0;
    printf("enter the strings:");
    fgets(str, sizeof(str), stdin);
    for (int i = 0; str[i] != '\0'; i++)

    {
        char ch = tolower(str[i]);
        if (isalpha(ch))
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                vowels++;
            }
            else if (isalpha(ch))
            {
                consonants++;
            }
            else if (isdigit(ch))
            {
                digits++;
            }
        }
        printf("number of vowels: %d\n", vowels);
        printf("number of consonants: %d\n", consonants);
        printf("number of digits: %d\n", digits);
        return 0;
    }
}