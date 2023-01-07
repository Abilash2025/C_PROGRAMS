#include <stdio.h>
#include <stdlib.h>


void insertion_sort(int array[],int length);


int main()
{
    int size;

    printf("Enter the size of array : ");
    scanf("%d" , &size);

    int a[size];

    printf("Enter the elements of array that has to be sorted : \n");

    for (int i = 0 ; i < size ; i++)
    {
        int element;
        scanf("%d" , &element);
        a[i] = element;
    }

    int length  = sizeof(a)/sizeof(a[0]);


    insertion_sort(a,length);

    return 0;
}


void insertion_sort(int array[],int length)
{

    for (int i = 1; i < length ; i++)
    {
        int current = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > current)
        {
            array[j+1] = array[j];
            j = j - 1;
        }
        array[j+1] = current;
    }

    printf("The sorted array is :");

    for (int i = 0; i < length ; i++)
    {
        printf(" %d" , array[i]);
    }
}
