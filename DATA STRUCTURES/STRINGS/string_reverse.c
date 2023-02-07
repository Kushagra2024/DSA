#include<stdio.h>
#include<string.h>
//This function finds the reverse of entered String
void str_rev(char str[]);
void swap(char arr[], int, int);

int main()
{
    char str[100];
    printf("Enter String: ");
    gets(str);
    str_rev(str);
    strrev(str);        //strrev()is a prefined function defined in string.h header file
    puts(str);
    return 0;
}

void swap(char arr[], int i, int j)
{
    char temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void str_rev(char str[])
{
    int n,i = 0;
    n = strlen(str);
    while (i < (n/2))
    {
        swap(str, i, (n-1-i));
        i++;
    }
}