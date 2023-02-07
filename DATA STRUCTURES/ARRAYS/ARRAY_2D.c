#include<stdio.h>

int main()
{
    /*-----------------------------------------Two-dimensional Arrays-----------------------------------------*/
    //Declaring Two-dimensional Arrays
    int marks_1[3][5];

    //Initializing Two-dimensional Arrays
    int marks_2[2][3] = {1,2,3,4,5,6};
    int marks_3[2][3] = {{1,2,3},{4,5,6}};
    int marks_4[][3] = {1,2,3,4,5,6};

    //Accessing the Elements of Two-dimensional Arrays
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t",marks_4[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}