#include<stdio.h>

//This function generates Pascal`s Triangle
void genPascal_triangle(int);
//This function generates nth row of Pascal`s Triangle
void genPascal_row(int);
//This function generates value of nth row & mth column of Pascal`s Triangle
void genPascal_value(int, int);

int main()
{
    int numRow, colNum;

    printf("\nEnter num of Rows: ");
    scanf("%d",&numRow);
    genPascal_triangle(numRow);
    
    printf("\nEnter Row number: ");
    scanf("%d",&numRow);
    genPascal_row(numRow);

    printf("\nEnter Row and Col Value: ");
    scanf("%d %d",&numRow,&colNum);
    genPascal_value(numRow, colNum);

    return 0;
}

//Time Complexity: O(n^2)
//Space Complexity: O(n)
void genPascal_triangle(int row)
{
    int mat[100] = {1}, i, j;

    printf("The Pascal triangle is: \n");
    for ( i = 0; i < row; i++)
    {   //This loop traverse backwards while finding sum of jth & j-1th term & updates the current array
        for ( j = i; j > 0; j--)
        {
            mat[j] = mat[j-1] + mat[j];
        }
        //This array prints the value of array
        for ( j = 0; j <= i; j++)
        {
            printf("%d\t", mat[j]);
        }
        printf("\n");
    }
}

//Time Complexity: O(n^2)
//Space Complexity: O(n)
void genPascal_row(int row)
{
    int mat[100] = {1}, i, j;

    printf("%dth Row of Pascal triangle is: \n",row);
    for ( i = 0; i < row; i++)
    {
        for ( j = i; j > 0; j--)
        {
            mat[j] = mat[j-1] + mat[j];
        }
    }
    for ( i = 0; i < row; i++)
    {
        printf("%d\t", mat[i]);
    }
    printf("\n");
}

//Time Complexity: O(n^2)
//Space Complexity: O(n)
void genPascal_value(int row, int col)
{
    int mat[100] = {1}, i, j;

    for ( i = 0; i < row; i++)
    {
        for ( j = i; j > 0; j--)
        {
            mat[j] = mat[j-1] + mat[j];
        }
    }
    printf("Value of %dth row & %dth column: %d", row, col, mat[col-1]);
}