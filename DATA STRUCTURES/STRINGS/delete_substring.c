#include<stdio.h>
//This function deletes the substring from the entered String
void delete_substr(char str[], int, int);

int main()
{
    char str[100] = "ABCDXXXABCD";
    int pos, len;

    printf("Enter postion: ");
    scanf("%d",&pos);
    printf("Enter Length: ");
    scanf("%d",&len);
    delete_substr(str, pos, len);
    return 0;
}

void delete_substr(char str[], int pos, int len)
{
    char temp[100];
    int i = 0, k = 0;

    printf("Original String: ");
    puts(str);
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
    printf("Modified String: ");
    puts(temp);
}