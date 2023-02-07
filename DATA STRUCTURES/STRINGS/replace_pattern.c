#include<stdio.h>
#include<string.h>
//This function repllaces a pattern with new pattern
void replace_pattern(char str[], char pat1[], char pat2[]);
int match_pattern(char str[],char pat[]);
void delete_substr(char str[], int pos, char pat[]);
void insert_str(char str[], int pos, char pat[]);

int main()
{
    char str[] = "AAABBBCCC";
    replace_pattern(str, "BBB", "X");   //str is passed as an modifiable argument i.e as an charecter array
    replace_pattern(str, "X", "BBB");   //other arguments are not passed as char array hence not modifiable

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
    if (i == (m-n+1))
    {
        return -1;
    }
    
}
void delete_substr(char str[], int pos, char pat[])
{
    char temp[100];
    int i = 0, k = 0, len = strlen(pat);

    while (str[i] != '\0')
    {
        if (i != pos)
        {
            temp[k] = str[i];
            k++, i++;
        }
        else
        {
            i += len;
        }
    }
    temp[k] = '\0';
    i = 0;
    while (temp[i] != '\0')
    {
        str[i] = temp[i];
        i++;
    }
    str[i] = '\0';
}
void insert_str(char str[], int pos, char pat[])
{
    char new_str[200];
    int i = 0, k = 0, j = 0;

    while (str[i] != '\0')
    {
        if (i == pos)
        {
            while (pat[j] != '\0')
            {
                new_str[k] = pat[j];
                k++;
                j++;
            }
            new_str[k] = str[i];
            i++;
            k++;
        }
        else
        {
            new_str[k] = str[i];
            k++;
            i++;
        }
    }
    new_str[k] = '\0';
    i = 0;
    while (i < strlen(new_str))
    {
        str[i] = new_str[i];
        i++;
    }
    str[i] = '\0';
}

void replace_pattern(char str[], char pat1[], char pat2[])
{
    int pos = match_pattern(str, pat1);
    delete_substr(str, pos, pat1);
    insert_str(str, pos, pat2);
    printf("New Pattern is: ");
    puts(str);
}