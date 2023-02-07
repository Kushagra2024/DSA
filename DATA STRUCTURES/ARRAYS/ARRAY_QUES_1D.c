#include<stdio.h>

void insert_into_sorted_array()
{
    int arr[10], i, j, size, num;

    printf("Enter number of elements in the array: ");
    scanf("%d", &size);

    printf("\nEnter elements in the sorted order in the array: ");
    for (i = 0; i < size; i++)
    {
        printf("\narray[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    
    printf("\nElements in array: ");
    for (i = 0; i < size; i++)
    {
        printf("%d\t",arr[i]);
    }

    printf("\nEnter number to be inserted: ");
    scanf("%d",&num);

    for (i = size-1; arr[i] > num; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[i+1] = num;

    printf("\nElements in array after insertion: ");
    for (i = 0; i < size+1; i++)
    {
        printf("%d\t",arr[i]);
    }
}

void delete_from_sorted_array()
{
    int arr[10], i, j, size, num;

    printf("Enter number of elements in the array: ");
    scanf("%d", &size);

    printf("\nEnter elements in the sorted order in the array: ");
    for (i = 0; i < size; i++)
    {
        printf("\narray[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    
    printf("\nElements in array: ");
    for (i = 0; i < size; i++)
    {
        printf("%d\t",arr[i]);
    }

    printf("\nEnter number to be deleted: ");
    scanf("%d",&num);

    //Method 1: By using two loops
    i = 0;
    while(arr[i] != num && i < size)
    {
        i++;
    }
    while (i < size-1)
    {
        arr[i] = arr[i+1];
        i++;
    }
    //Method 2: By using Single Loop
    for (i = 0; i < size-1; i++)
    {
        if (arr[i] >= num)
        {
            arr[i] = arr[i+1];
        }
    }
    
    size--;
    printf("\nElements in array after deletion: ");
    for (i = 0; i < size; i++)
    {
        printf("%d\t",arr[i]);
    }

}

//This function deletes the first occurance of number from the array
void delete_from_array()
{
    int arr[10], i, num, k, size;

    printf("Enter number of elements in the array: ");
    scanf("%d", &size);

    printf("Enter the Element in the array: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter num to be deleted: ");
    scanf("%d", &num);
    for (i = 0, k = -1; i < size-1; i++)
    {
        if ((arr[i] == num) && (k == -1))
        {
            k = i;
        }
        if (k != -1)
        {
            arr[k] = arr[k+1];
            k++;
        }
    }
    printf("Elements in array after deletion: ");
    for ( i = 0; i < size-1; i++)
    {
        printf("%d\t", arr[i]);
    }
}

void createArray(int arr[], int size)
{
    int i;
    printf("\nEnter elements in array:");
    for (i = 0; i < size; i++)
    {
        printf("\narr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
}

void displayArray(int arr[], int size)
{
    int i;
    printf("\nElements in array: ");
    for (i = 0; i < size; i++)
    {
        printf("%d\t",arr[i]);
    }
}

int findmax(int arr[], int size)
{
    int max, i;
    max = 0;
    for ( i = 1; i < size; i++)
    {
        if (arr[i] > arr[max])
        {
            max = i;
        }
    }
    return max;
}

int findmin(int arr[], int size)
{
    int min, i;
    min = 0;
    for (i = 1; i < size; i++)
    {
        if (arr[i] < arr[min])
        {
            min = i;
        }
    }
    return min;
}

void interchange(int *arr, int min, int max)
{
    int temp;
    temp = arr[max];
    arr[max] = arr[min];
    arr[min] = temp;
}

void interchange_max_min(int arr[], int size)
{
    int min, max;
    min = findmin(arr, size);
    max = findmax(arr, size);
    interchange(arr, min ,max);
}

int main()
{
    //Write a program to insert a number in an array that is already sorted in ascending order.
    insert_into_sorted_array();

    //Write a program to delete a number from an array that is already sorted in ascending order.
    delete_from_sorted_array();

    //Write a program to delete a number from both sorted and unsorted array.
    delete_from_array();

    //Write a program to interchange the largest and the smallest number in an array.
    int arr[10], size;

    printf("Enter size of array: ");
    scanf("%d", &size);
    createArray(arr, size);
    displayArray(arr, size);
    interchange_max_min(arr, size);
    displayArray(arr, size);

    return 0;
}