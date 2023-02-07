#include<stdio.h>
#include<string.h>
//This function matches the pattern with String - Commonly known as NAIVE STRING MATCHING
void match_pattern(char str[], char pat[]);

int main()
{
    char str_1[100], str_2[100];

    printf("Enter string: ");
    gets(str_1);
    printf("Enter Pattern: ");
    gets(str_2);
    match_pattern(str_1, str_2);
    return 0;
}



void match_pattern(char str[],char pat[])
{
    int m, n, i, k;
    m = strlen(str);
    n = strlen(pat);

    for (i = 0; i < m-n+1; i++)
    {
        for (k = 0; k < n; k++)
        {
            if (str[i + k] != pat[k])
            {
                break;
            }
        }
        if (k == n)
        {
            printf("Pattern Match at %d index\n", i);
        }
    }
    if (i == (m-n+1))
    {
        printf("Pattern not Present!\n");
    }
}