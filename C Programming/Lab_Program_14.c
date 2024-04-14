/*
NAME :- ABHINAV SINGH
BRANCH :- ECE
SECTION :- A
ROLL NUMBER :- 2023ECE096
EXAM ROLL NUMBER :- 23294917096
ENROLLMENT NUMBER :- 23DOECBTEC000096
*/

/*
Write C program to implement Bubble sort using function.
*/

#include <stdio.h>
#include <stdbool.h>

void swap(int *x,int *y)
{
    int temp = *x;
    *x=*y;
    *y = temp;
}

void bubble_sort(int arr[],int n)
{
    bool swapped;
    for(int i = 0;i<n-1;i++)
    {
        swapped=false;
        for(int j = 0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                swapped = true;
            }
        }
        if(swapped==false)
            break;
    }
}

void print_array(int arr[],int size)
{
    for(int i = 0;i<size;i++)
        printf("%d ",arr[i]);
}

int main(void)
{
    int arr[]={10,6,5,2,3,4,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,n);
    printf("Sorted array: \n");
    print_array(arr,n);
}