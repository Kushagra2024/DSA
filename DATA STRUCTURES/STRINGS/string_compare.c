#include<stdio.h>
#include<string.h>
//This function compares two String
void str_comp(char str1[], char str2[]);

int main()
{
    char str_1[100], str_2[100],result;
    printf("Enter First String: ");
    gets(str_1);
    printf("Enter Second String: ");
    gets(str_2);
    str_comp(str_1, str_2);

    //Using Prefined function strcmp() which is defined in string.h headr file
    //strcmp() returns 0 for equal strings, -1 for str1>str2 & else 1
    result = strcmp(str_1, str_2);
    if (result == -1)
    {
        printf("%s comes alphabetically first\n", str_1);
    }
    else if (result == 1)
    {
        printf("%s comes alphabetically first\n", str_2);
    }
    else
    {
        printf("Both Strings are Equal");
    }
    
    return 0;
}

void str_comp(char str1[],char str2[])
{
    int m, n, i = 0;

    m = strlen(str1);
    n = strlen(str2);

    if(m != n)
    {
        printf("Strings are not equal\n");
        return;
    }
    while (i < m)
    {
        if (str1[i] < str2[i])
        {
            printf("%s comes alphabetically first\n", str1);
            break;
        }
        else if(str2[i] < str1[i])
        {
            printf("%s comes alphabetically first\n", str2);
            break;
        }
        else
        {
            i++;
        }
    }
    if (i == m)
    {
        printf("Both Strings are equal");
    }
}