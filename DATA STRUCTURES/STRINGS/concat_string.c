#include<stdio.h>
#include<string.h>
//This function concatenates two Strings
void concat_str(char str[],char str_1[], char str_2[]);

int main()
{
    char str_1[100], str_2[100], new_str[200];
    printf("Enter First String: ");
    gets(str_1);
    printf("Enter Second String: ");
    gets(str_2);

    concat_str(new_str, str_1, str_2);
    printf("Concatenated String is: ");
    puts(new_str);
    puts(strcat(str_1,str_2));      //Using Predefined function strcat() defined in string.h header file
    return 0;
}

void concat_str(char str[], char str_1[], char str_2[])
{
    int m, n, i = 0, j = 0;
    m = strlen(str_1);
    n = strlen(str_2);

    for (i = 0; i < m; i++)
    {
        str[i] = str_1[i];
    }
    for ( j = 0; j < n; j++, i++)
    {
        str[i] = str_2[j];
    }
    str[i] = '\0';
}