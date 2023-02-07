#include<stdio.h>

int main()
{
/*----------------------------------------------Declaring String----------------------------------------------*/
    /*char str_1[] = "Kush";      //size of string is not mentioned during initialization
    printf("%s",str_1);

    char str_2[4] = "Kush";     //size of string is mention but not correct - no space for NULL charecter
    printf("%s",str_2);

    char str_3[5] = "Kush";     //size of string is mention with space for NULL charecter
    printf("%s",str_3);

    char ch = 'k';              //here, ch is declared as charecter
    printf("%c",ch);

    char str_4[] = {'k', 'u', 's', 'h', '\0'};      //declared as array of charecters format
    printf("%s", str_4);

    char str_5[4] = {'k', 'u', 's', 'h'};          //NULL charecter not placed
    printf("%s",str_5);

    char str_6[4] = {'k', 'u', 's', 'h','\0'};      //Charecters more than size of arraay
    printf("%s",str_6);

    char str_7[5];
    str_7[5] = "Kush";      //illegal - initialization cannot be separated from declaration
    printf("%s",str_7);*/

/*----------------------------------------------Reading String----------------------------------------------*/
    //By Using scanf() Function
    char str[100];
    // printf("Enter string: ");
    // scanf("%s",str);        //limitations : only a single string can be entered. Space seperated strings are discarded

    //By Using gets() function
    printf("Enter String: ");
    gets(str);      //This method overcomes the limitations of scanf function

    //By using getchar(), getch(), getche() fxn

/*----------------------------------------------Writing String----------------------------------------------*/
    //By using printf() function
    printf("String is: %s\n",str);

    //By using puts() function
    puts(str);

    return 0;
}