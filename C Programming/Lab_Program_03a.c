#include <stdio.h>

int binary_search(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;

        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    int n;
    printf("Enter the number of the elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array in the sorted order: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the element to be targeted: ");
    scanf("%d", &target);

    int index = binary_search(arr, n, target);

    if (index != -1)
        printf("Elements %d is found at index %d\n", target, index);
    else
        printf("Element %d is not found in the array\n", target);

    return 0;
}