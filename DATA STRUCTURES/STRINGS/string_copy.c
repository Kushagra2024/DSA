#include<stdio.h>
#include<string.h>

//This function copies the content
void str_cpy(char str2[], char str1[]);

int main()
{
    char str1[100],str2[100];
    printf("Enter String: ");
    gets(str1);
    str_cpy(str1,str2);
    strcpy(str2, str1);     //this is a prefined function which copies content of source string to destination string. Note: Notice the order
    printf("Copied String is: ");
    puts(str2);

    return 0;
}

void str_cpy(char str1[], char str2[])
{
    int i = 0;
    while (str1[i] != '\0')
    {
        str2[i] = str1[i];
        i++;
    }
    str2[i] = '\0';
}