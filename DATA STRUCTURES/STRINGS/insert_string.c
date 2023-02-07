#include<stdio.h>
//This function inserts the substring into entered String
void insert_str(char str[], int);

int main()
{
    char str[100];

    printf("Enter String: ");
    gets(str);
    insert_str(str, 4);
    return 0;
}

void insert_str(char str[], int pos)
{
    char text[100], new_str[200];
    int i = 0, k = 0, j = 0;

    printf("Enter text: ");
    gets(text);

    while (str[i] != '\0')
    {
        if (i == pos)
        {
            while (text[j] != '\0')
            {
                new_str[k] = text[j];
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
    printf("Resultant String: ");
    puts(new_str);
}