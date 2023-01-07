#include <stdio.h>
#include <stdlib.h>

int binary_search(int array[] , int element , int left_index , int right_index);

int main()
{

    int size;
    printf("Enter the size of array : ");
    scanf("%d",&size);

    int a[size];

    printf("enter the elements of array : \n");

    for(int i = 0 ; i < size ; i++)
    {
        int arr_elements;
        scanf("%d",&arr_elements);
        a[i] = arr_elements;
    }

    int element;
    printf("Enter the element to search : ");
    scanf("%d",&element);

    for (int i = 1 ; i < size ; i++)
    {
        int current = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > current)
        {
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1] = current;
    }
    
    int left_index = 0;
    int right_index = size - 1;

    int index = binary_search(a , element , left_index , right_index);

    printf("The index of the element is %d" , index);

    return 0;
}

int binary_search(int arr[] , int element , int left_index , int right_index)
{

    int mid_index = (left_index + right_index)/2;
    if (left_index > right_index)
    {
        return -1;
    }
    else
    {
        if (arr[mid_index] == element)
        {
            return mid_index;
        }
        else if (arr[mid_index] > element)
        {
            return binary_search(arr , element , left_index , mid_index - 1);
        }
        else if (arr[mid_index] < element)
        {
            return binary_search(arr,element,mid_index + 1 , right_index);
        }
    }
}
