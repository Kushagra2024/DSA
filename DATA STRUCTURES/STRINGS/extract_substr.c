#include<stdio.h>
#include<string.h>
//This function finds the substring from given String
void extract_substr(char str[]);

int main()
{
    char str[100], index, len;
    printf("Enter String: ");
    gets(str);
    extract_substr(str);

    return 0;
}

void extract_substr(char str[])
{
    char temp[100];
    int index, len, i, k = 0, n;
    printf("Enter Index: ");
    scanf("%d", &index);
    printf("Enter Length of Substring: ");
    scanf("%d", &len);
    i = index;
    n = strlen(str);
    while ((i < n) && (str[i] != '\0' && len > 0))
    {
        temp[k] = str[i];
        k++;
        i++;
        len--;
    }
    temp[k] = '\0';
    printf("Given String is: ");
    puts(str);
    printf("\nSubstring is: ");
    puts(temp);
}