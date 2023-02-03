#include<stdio.h>
#include<stdlib.h>

void dynamicArray(void)
{
    int i, size, *arr;

    printf("Enter size of Array: ");
    scanf("%d",&size);

    arr = (int *)calloc(size,sizeof(int));

    if(arr == NULL)
    {
        printf("No memory allocated!");
    }
    else
    {
        for (i = 0; i < size; i++)
        {
            printf("\nEnter %d element in Array: ",i);
            scanf("%d",&arr[i]);
        }
        printf("\nElements in Array: ");
        for (i = 0; i < size; i++)
        {
            printf("%d ",arr[i]);
        }
    }
}
void storeArray(void)
{
    //1) Initializing Arrays during Declaration
        int marks_1[6] = {1,2,3,4,5,6};
        int marks_2[] = {10,20,30};     //size can be ommitted if initialization during declaration
        int marks_3[5] = {1,2};         //if values providedd are less than size, unassigned values are filled with zeros. [1,2,0,0,0]
        int marks_4[5] = {0};           //can be used for initializing array with zeros. [0,0,0,0,0]

    //2) Inputting Values from the Keyboard
        int i, marks[10];
        for(i= 0; i<10; i++)
            scanf("%d", &marks[i]);
}
void traverseArray(void)
{
    int i, arr[10], n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\narr[%d] = ",i);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        printf("\narr[%d] = %d",i,arr[i]);
    }
}
void insertArray(void)
{
    //Insert an Element at the End of an Array
    int marks_1[60];
    marks_1[54] = 68;

    //Insert an Element in the Middle of an Array
    int marks_2[10], size, i, pos;
    printf("Enter number of Elements in the array: ");
    scanf("%d",&size);

    printf("Enter marks:\n");
    for (i = 0; i < size; i++)
    {
        printf("\nmarks[%d]: ",i);
        scanf("%d",&marks_2[i]);
    }
    printf("Marks in Array\n");
    for (i = 0; i < size; i++)
    {
        printf("\nmarks[%d]: %d",i,marks_2[i]);
    }
    printf("Enter position at which marks to be inserted: ");
    scanf("%d",&pos);
    for (i = size-1; i >= pos-1; i--)
    {
        marks_2[i+1] = marks_2[i];
    }
    printf("Enter marks at %d position: ", pos);
    scanf("%d",marks_2[pos]);
    size++;
    printf("\nMarks in Array");
    for (i = 0; i < size; i++)
    {
        printf("\nmarks[%d]: %d",i,marks_2[i]);
    }
}
void deleteArray(void)
{
    //delete an element from the end of an array
    int marks_1[54];
    marks_1[53];

    //delete an element from the middle of an array
    int marks_2[10], size, i, pos;
    printf("Enter number of Elements in the array: ");
    scanf("%d",&size);

    printf("Enter marks:\n");
    for (i = 0; i < size; i++)
    {
        printf("\nmarks[%d]: ",i);
        scanf("%d",&marks_2[i]);
    }
    printf("Marks in Array\n");
    for (i = 0; i < size; i++)
    {
        printf("\nmarks[%d]: %d",i,marks_2[i]);
    }
    printf("\nEnter position from which marks to be deleted: ");
    scanf("%d",&pos);
    for (i = pos-1; i < size-1; i++)
    {
        marks_2[i] = marks_2[i+1];
    }
    size--;
    printf("\nMarks in Array");
    for (i = 0; i < size; i++)
    {
        printf("\nmarks[%d]: %d",i,marks_2[i]);
    }
}
void mergeArray(void)
{
    //merge operation on unsorted arrays
    /*
    {
        int arr_1[10], arr_2[10], arr_3[20], size_1, size_2, size_3, i;

        printf("\nEnter size of 1st array: ");
        scanf("%d", &size_1);

        printf("\nEnter elements in 1st array: ");
        for (i = 0; i < size_1; i++)
        {
            printf("\narray_1[%d]: ",i);
            scanf("%d",&arr_1[i]);
        }
        
        printf("\nElements in 1st array: ");
        for (i = 0; i < size_1; i++)
        {
            printf("%d\t",arr_1[i]);
        }

        printf("\nEnter size of 2nd array: ");
        scanf("%d", &size_2);

        printf("\nEnter elements in 2nd array: ");
        for (i = 0; i < size_2; i++)
        {
            printf("\narray_2[%d]: ",i);
            scanf("%d",&arr_2[i]);
        }
        
        printf("\nElements in 2nd array: ");
        for (i = 0; i < size_2; i++)
        {
            printf("%d\t",arr_2[i]);
        }

        size_3 = size_1 + size_2;
        for (i = 0; i < size_1; i++)
        {
            arr_3[i] = arr_1[i];
        }
        for (i = 0; i < size_2; i++)
        {
            arr_3[size_1+i] = arr_2[i];
        }
        
        printf("\nElements in merged array: ");
        for (i = 0; i < size_3; i++)
        {
            printf("%d\t",arr_3[i]);
        }
    }
    */
    //merge operation on sorted arrays
    /*
    {
        int arr_4[10], arr_5[10], arr_6[20], size_4, size_5, size_6, j, k, x;

        printf("\nEnter size of 1st array: ");
        scanf("%d", &size_4);

        printf("\nEnter elements in sorted order in 1st array: ");
        for (j = 0; j < size_4; j++)
        {
            printf("\narray_1[%d]: ",j);
            scanf("%d",&arr_4[j]);
        }
        
        printf("\nElements in 1st array: ");
        for (j = 0; j < size_4; j++)
        {
            printf("%d\t",arr_4[j]);
        }

        printf("\nEnter size of 2nd array: ");
        scanf("%d", &size_5);

        printf("\nEnter elements in sorted order in 2nd array: ");
        for (j = 0; j < size_5; j++)
        {
            printf("\narray_2[%d]: ",j);
            scanf("%d",&arr_5[j]);
        }
        
        printf("\nElements in 2nd array: ");
        for (j = 0; j < size_5; j++)
        {
            printf("%d\t",arr_5[j]);
        }

        //Copying elements from 1st and 2nd array to 3rd array
        j = k = x = 0;
        while (j < size_4 && k < size_5)
        {
            if (arr_4[j] < arr_5[k])
            {
                arr_6[x] = arr_4[j];
                x++, j++;
            }
            else
            {
                arr_6[x] = arr_5[k];
                x++, k++;
            }
        }
        // if elements of the first array are over and the second array has some elements
        while (j = size_4 && k < size_5)
        {
            arr_6[x] = arr_5[k];
            x++, k++;
        }
        // if elements of the second array are over and the first array has some elements
        while (k = size_5 && j < size_4)
        {
            arr_6[x] = arr_4[j];
            x++, j++;          
        }

        size_6 = size_4 + size_5;
        printf("\nElements in merged array: ");
        for (j = 0; j < size_6; j++)
        {
            printf("%d\t",arr_6[j]);
        }
    }
    */
}


int main()
{
/*----------------------------------------------Creating arrays----------------------------------------------*/
    // dynamicArray();

/*------------------------------------------Storing Values in arrays------------------------------------------*/
    //1) Initializing Arrays during Declaration
    //2) Inputting Values from the Keyboard
    // storeArray();

/*--------------------------------------------OPERATIONS ON ARRAYS--------------------------------------------*/
    //1) Traversing an Array
    //2) Inserting an Element in an Array
    //3) Deleting an Element from an Array
    //4) Merging Two Arrays
    // traverseArray();
    // insertArray();
    // deleteArray();
    // mergeArray();

    return 0;
}