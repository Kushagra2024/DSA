#include<stdio.h>
#include<string.h>
//This function replaces a pattern with new pattern
void replace_pattern(char str[], char pat1[], char pat2[]);
int match_pattern(char str[],char pat[]);
void insert_str(char str[], char pat1[], char pat2[], int pos);

int main()
{
    char str[] = "AAABBBCCC";
    replace_pattern(str, "BBB", "X");   //str is passed as an modifiable argument i.e as an charecter array
    replace_pattern(str, "X", "BBB");   //other arguments are not passed as char array hence not modifiable
    replace_pattern(str, "CCC", "Y");   //other arguments are not passed as char array hence not modifiable

    return 0;
}

int match_pattern(char str[],char pat[])
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
            return i;
        }
    }
    return -1;
    
}
void insert_str(char str[], char pat1[], char pat2[], int pos)
{
    char new_str[200];
    int i = 0, k = 0, j = 0;

    while (str[i] != '\0')
    {
        if (i == pos)
        {
            while (pat2[j] != '\0')
            {
                new_str[k] = pat2[j];
                k++;
                j++;
            }
            i = i + strlen(pat1);
        }
        else
        {
            new_str[k] = str[i];
            k++;
            i++;
        }
    }
    new_str[k] = '\0';
    strcpy(str, new_str);
}

void replace_pattern(char str[], char pat1[], char pat2[])
{
    int pos = match_pattern(str, pat1);
    insert_str(str, pat1, pat2, pos);
    printf("New Pattern is: ");
    puts(str);
}