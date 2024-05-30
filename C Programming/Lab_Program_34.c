/*
NAME :- ABHINAV SINGH
BRANCH :- ECE
SECTION :- A
ROLL NUMBER :- 2023ECE096
EXAM ROLL NUMBER :- 23294917096
ENROLLMENT NUMBER :- 23DOECBTEC000096
*/

/*
max_heap (creation, insertion, deletion, search, display)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct MaxHeap
{
    int array[MAX_SIZE];
    int size;
} MaxHeap;

MaxHeap *createMaxHeap()
{
    MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
    heap->size = 0;
    return heap;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(MaxHeap *heap, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->array[left] > heap->array[largest])
        largest = left;

    if (right < heap->size && heap->array[right] > heap->array[largest])
        largest = right;

    if (largest != index)
    {
        swap(&heap->array[index], &heap->array[largest]);
        maxHeapify(heap, largest);
    }
}

void insert(MaxHeap *heap, int value)
{
    if (heap->size == MAX_SIZE)
    {
        printf("Heap is full. Insertion failed.\n");
        return;
    }

    int index = heap->size;
    heap->array[index] = value;
    heap->size++;

    while (index > 0 && heap->array[(index - 1) / 2] < heap->array[index])
    {
        swap(&heap->array[index], &heap->array[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

int deleteMax(MaxHeap *heap)
{
    if (heap->size == 0)
    {
        printf("Heap is empty. Deletion failed.\n");
        return -1;
    }

    int max = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    maxHeapify(heap, 0);

    return max;
}

int search(MaxHeap *heap, int value)
{
    for (int i = 0; i < heap->size; i++)
    {
        if (heap->array[i] == value)
        {
            return i;
        }
    }
    return -1;
}

void display(MaxHeap *heap)
{
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++)
    {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

int main()
{
    MaxHeap *heap = createMaxHeap();
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete Max\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(heap, value);
            break;
        case 2:
            value = deleteMax(heap);
            if (value != -1)
            {
                printf("Deleted maximum element: %d\n", value);
            }
            break;
        case 3:
            printf("Enter value to search: ");
            scanf("%d", &value);
            int index = search(heap, value);
            if (index != -1)
            {
                printf("%d found at index %d\n", value, index);
            }
            else
            {
                printf("%d not found in the heap\n", value);
            }
            break;
        case 4:
            display(heap);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
