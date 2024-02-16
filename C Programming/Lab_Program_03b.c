#include <stdio.h>

int binary_search(int arr[], int left, int right, int target)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] > target)
            return binary_search(arr, left, mid - 1, target);

        return binary_search(arr, mid + 1, right, target);
    }

    return -1;
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the element of the array in sorted order: \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the element to be searched: ");
    scanf("%d", &target);

    int index = binary_search(arr, 0, size - 1, target);

    if (index != -1)
        printf("Element %d is found at index %d\n", target, index);
    else
        printf("Element is not present in the array\n", target);
    
    return 0;
}