#include<stdio.h>

void salesman()
{
    int arr[4][3], i, j, sum;

    for (i = 0; i < 4; i++)
    {
        printf("Enter sales of three items of salesman %d: ", i+1);
        for (j = 0; j < 3; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Salesman  Item 1\tItem 2\tItem 3");
    for (i = 0; i < 4; i++)
    {
        printf("\n%d",i+1);
        for (j = 0; j < 3; j++)
        {
            printf("\t\t%d",arr[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < 4; i++)
    {
        sum = 0;
        for ( j = 0; j < 3; j++)
        {
            sum += arr[i][j];
        }
        printf("\nTotal sales by Salesman %d: %d", i+1, sum);
    }
    for (i = 0; i < 3; i++)
    {
        sum = 0;
        for (j = 0; j < 4; j++)
        {
            sum += arr[j][i];
        }
        printf("\nTotal Sales of Item %d: %d", i+1, sum);
    }
}

void findmaxmarks()
{
    int marks[4][3], i,j, max;
    
    for (i = 0; i < 4; i++)
    {
        printf("Enter marks of Student %d in three subjects: ", i+1);
        for (j = 0; j < 3; j++)
        {
            scanf("%d",&marks[i][j]);
        }
    }
    printf("Student\tSubject 1\tSubject 2\tSubject 3");
    for (i = 0; i < 4; i++)
    {
        printf("\n%d", i+1);
        for (j = 0; j < 3; j++)
        {
            printf("\t\t%d",marks[i][j]);
        }
    }
    for (i = 0; i < 4; i++)
    {
        max = marks[i][0];
        for (j = 1; j < 3; j++)
        {
            if (marks[i][j] > max)
            {
                max = marks[i][j];
            }
        }
        printf("\nMax Marks of Student %d: %d",i+1, max);
    }
}

int main()
{
    /*In a small company there are four salesmen. Each salesman is supposed to sell three products. Write a program using a 2D array to print
    (i) the total sales by each salesman and
    (ii) total sales of each item.*/
    salesman();

    /*Write a program to read a 2D array marks which stores the marks of four students in three subjects. Write a program to display the highest marks in each subject.*/
    findmaxmarks();

    return 0;
}