#include<stdio.h>
#include<ctype.h>
//These functions converts the string into UPPER case and LOWER case
void convert_lower_to_upper(char str[]);
void convert_upper_to_lower(char str[]);

int main()
{
    char str[100];
    printf("Enter String: ");
    gets(str);
    printf("Entered String is: ");
    puts(str);

    convert_upper_to_lower(str);
    convert_lower_to_upper(str);

    return 0;
}

void convert_lower_to_upper(char str[])
{
    int i = 0;
    char new_str[100];
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            // new_str[i] = str[i] - 32;       //uppercase charecter = lowercase charecter - 32
            new_str[i] = toupper(str[i]);      //using predefined function which is defined in ctype.h header file
        }
        else
        {
            new_str[i] = str[i];
        }
        i++;
    }
    new_str[i] = '\0';
    printf("\nString after converting to uppercase :");
    puts(new_str);
}

void convert_upper_to_lower(char str[])
{
    int i = 0;
    char new_str[100];
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            // new_str[i] = str[i] + 32;       //lowercase charecter = uppercase charecter - 32
            new_str[i] = tolower(str[i]);      //using predefined function which is defined in ctype.h header file
        }
        else
        {
            new_str[i] = str[i];
        }
        i++;
    }
    new_str[i] = '\0';
    printf("\nString after converting to lowercase :");
    puts(new_str);
}