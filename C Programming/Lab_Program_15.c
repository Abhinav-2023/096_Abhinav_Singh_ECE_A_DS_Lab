/*
NAME :- ABHINAV SINGH
BRANCH :- ECE
SECTION :- A
ROLL NUMBER :- 2023ECE096
EXAM ROLL NUMBER :- 23294917096
ENROLLMENT NUMBER :- 23DOECBTEC000096
*/

/*
Write C program to implement Insertion sort using function.
*/

#include <stdio.h>
#include <math.h>

void insertion_sort(int arr[], int n)
{
    int i, j, key;
    for (i = 0; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int arr[] = {10, 5, 6, 7, 3, 1, 8, 9, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, n);
    print_array(arr, n);
}