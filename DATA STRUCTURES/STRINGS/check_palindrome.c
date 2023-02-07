#include<stdio.h>
#include<string.h>

//This function checks for palindrome
void check_palindrome(char str[]);

int main()
{
    char str[100];

    printf("Enter string: ");
    gets(str);
    check_palindrome(str);
    return 0;
}

void check_palindrome(char str[])
{
    int i = 0, j = (strlen(str)-1);

    while (i < j)
    {
        if (str[i] != str[j])
        {
            printf("%s is not a palindrome!", str);
            break;
        }
        else
        {
            i++, j--;
        }
    }
    if (i >= j)
    {
        printf("%s is a Palindrome!", str);
    }
}