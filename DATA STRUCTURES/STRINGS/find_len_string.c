#include<stdio.h>
#include<string.h>
//This function finds the length of entered String
void len(char str[]);

int main()
{
    char str[100];

    printf("Enter string: ");
    gets(str);
    printf("Entered string is: ");
    puts(str);
    len(str);
    printf("\nLength of String is: %d", strlen(str));       //predefined fxn for finding length of string defined in string.h header file

    return 0;
}

void len(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    printf("Length of String is: %d", i);
}