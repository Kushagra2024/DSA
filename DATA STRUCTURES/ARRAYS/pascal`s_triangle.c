#include<stdio.h>

//This function generates Pascal`s Triangle
void genPascal_triangle(int);
//This function generates nth row of Pascal`s Triangle
void genPascal_row(int);
//This function generates value of nth row & mth column of Pascal`s Triangle
int genPascal_value(int, int);

int binCofficient(int, int);
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
    printf("Value of %dth row & %dth column: %d", numRow, colNum, genPascal_value(numRow, colNum));

    return 0;
}

void genPascal_triangle(int row)
{
    //Method 1
        //Time Complexity: O(n^2)
        //Space Complexity: O(n)
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

    //Method 2
        //Time Complexity: O(n^2)
        //Space Complexity: O(1)
    {
        int result, i, j, num, den;
        printf("%dth Row of Pascal triangle is: \n",row);
        for ( j = 1; j <= row; j++)
        {
            for ( i = 1, result = 1, num = 1, den = 1; i <= j; i++)
            {
                printf("%d\t", result);
                num *= (j-i);
                den *= i;
                result = num/den;
            }
            printf("\n");
        }
    }
}

void genPascal_row(int row)
{
    //Method 1
        //Time Complexity: O(n^2)
        //Space Complexity: O(n)
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

    //Method 2
        //Time Complexity: O(n)
        //Space Complexity: O(1)
    {
        int result = 1, i, num = 1, den = 1;
        printf("%dth Row of Pascal triangle is: \n",row);
        for ( i = 1; i <= row; i++)
        {
            printf("%d\t", result);
            num *= (row-i);
            den *= i;
            result = num/den;
        }
        printf("\n");
    }
}

int genPascal_value(int row, int col)
{
    //Method 1
        //Time Complexity: O(n^2)
        //Space Complexity: O(n)
    {    
       int mat[100] = {1}, i, j;

        for ( i = 0; i < row; i++)
        {
            for ( j = i; j > 0; j--)
            {
                mat[j] = mat[j-1] + mat[j];
            }
        }
        return mat[col-1];
    }

    //Method 2
        //Time Complexity: O(n)
        //Space Complexity: O(1)
    {
        return(binCofficient(row, col));
    }


}

int binCofficient(int n, int r)
{
    int i, result,num = 1, dem = 1;
    n -= 1;
    r -= 1;

    for ( ; r > 0; n--, r--)
    {
        num *= n;
        dem *= r;
    }
    result = num/dem;
    return result;
}