/*
NAME :- ABHINAV SINGH
BRANCH :- ECE
SECTION :- A
ROLL NUMBER :- 2023ECE096
EXAM ROLL NUMBER :- 23294917096
ENROLLMENT NUMBER :- 23DOECBTEC000096
*/

/*
Write C program to implement Quick sort using function.
*/

#include <stdio.h> 

void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

int partition(int arr[], int low, int high) 
{ 
    int pivot = arr[low]; 
    int i = low; 
    int j = high; 

    while (i < j) 
    {
        while (arr[i] <= pivot && i <= high - 1) 
        { 
            i++; 
        } 

        while (arr[j] > pivot && j >= low + 1)
        { 
            j--; 
        } 
    
        if (i < j) 
        { 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[low], &arr[j]); 
    return j; 
} 

void quick_sort(int arr[], int low, int high) 
{ 
    if (low < high) { 

    int partition_index = partition(arr, low, high); 

    quick_sort(arr, low, partition_index - 1); 
    quick_sort(arr, partition_index + 1, high); 
    } 
} 

int main(void) 
{ 
    int arr[] = { 19, 17, 15, 12, 16, 18, 4, 11, 13 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 

    printf("Original array: "); 
    for (int i = 0; i < n; i++) 
    { 
        printf("%d ", arr[i]); 
    } 

    quick_sort(arr, 0, n - 1); 

    printf("\nSorted array: "); 
    for (int i = 0; i < n; i++) 
    { 
        printf("%d ", arr[i]); 
    } 
}