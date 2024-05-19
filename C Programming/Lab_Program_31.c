/*
NAME :- ABHINAV SINGH
BRANCH :- ECE
SECTION :- A
ROLL NUMBER :- 2023ECE096
EXAM ROLL NUMBER :- 23294917096
ENROLLMENT NUMBER :- 23DOECBTEC000096
*/

/*
Implement C Program for Breadth First Search or BFS for a Graph.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

typedef struct Graph
{
    int numVertices;
    Node **adjLists;
    int *visited;
} Graph;

typedef struct Queue
{
    int items[MAX];
    int front;
    int rear;
} Queue;

Node *createNode(int v)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph *createGraph(int vertices)
{
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(Node *));
    graph->visited = malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
    Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

Queue *createQueue()
{
    Queue *queue = malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(Queue *queue)
{
    if (queue->rear == -1)
        return 1;
    return 0;
}

void enqueue(Queue *queue, int value)
{
    if (queue->rear == MAX - 1)
        printf("\nQueue is Full!!");
    else
    {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

int dequeue(Queue *queue)
{
    int item;
    if (isEmpty(queue))
    {
        printf("Queue is empty");
        item = -1;
    }
    else
    {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear)
        {
            queue->front = queue->rear = -1;
        }
    }
    return item;
}

void printQueue(Queue *queue)
{
    int i = queue->front;
    if (isEmpty(queue))
    {
        printf("Queue is empty");
    }
    else
    {
        printf("\nQueue contains \n");
        for (i = queue->front; i < queue->rear + 1; i++)
        {
            printf("%d ", queue->items[i]);
        }
    }
}

void BFS(Graph *graph, int startVertex)
{
    Queue *queue = createQueue();
    graph->visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isEmpty(queue))
    {
        printQueue(queue);
        int currentVertex = dequeue(queue);
        printf("Visited %d\n", currentVertex);

        Node *temp = graph->adjLists[currentVertex];

        while (temp)
        {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0)
            {
                graph->visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }
}

int main()
{
    Graph *graph = createGraph(MAX);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    BFS(graph, 0);

    return 0;
}
