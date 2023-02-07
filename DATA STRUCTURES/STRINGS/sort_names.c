#include<stdio.h>
#include<string.h>

//This function sorts the name alphabetically
void sort_names(char arr[][100], int);
void read_2d_array(char arr[][100], int);
void print_2d_array(char arr[][100], int);

int main()
{
    char name[100][100];
    int n = 3;
    // printf("Enter number of Students: ");
    // scanf("%d", &n);
    read_2d_array(name, n);
    printf("Names Before Sorting\n");
    print_2d_array(name, n);
    sort_names(name, n);
    printf("Names After Sorting\n");
    print_2d_array(name, n);
    return 0;
}

void read_2d_array(char name[][100], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("Enter name of %d Student: ", i+1);
        gets(name[i]);
    }
}

void print_2d_array(char name[][100], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("Name of %d Student: ", i+1);
        puts(name[i]);
    }
}

void sort_names(char name[][100], int size)
{
    char temp[100];
    int i,j;
    for ( i = 0; i < size-1; i++)
    {
        for ( j = 0; j < size-1-i; j++)
        {
            if (strcmp(name[j], name[j+1]) > 0)
            {
                strcpy(temp, name[j]);
                strcpy(name[j], name[j+1]);
                strcpy(name[j+1], temp);
            }
        }
    }
}