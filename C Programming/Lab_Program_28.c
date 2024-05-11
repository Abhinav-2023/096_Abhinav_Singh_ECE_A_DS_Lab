/*
NAME :- ABHINAV SINGH
BRANCH :- ECE
SECTION :- A
ROLL NUMBER :- 2023ECE096
EXAM ROLL NUMBER :- 23294917096
ENROLLMENT NUMBER :- 23DOECBTEC000096
*/

/*
Write a menu driven program to implement Adjacency Matrix of a given
a) undirected graph and 
b)directed graph
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int adjMatrix[MAX_VERTICES][MAX_VERTICES];
int numVertices = 0;

void initGraph()
{
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        for (int j = 0; j < MAX_VERTICES; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(int source, int destination, int directed)
{
    if (source >= numVertices || destination >= numVertices)
    {
        printf("Error: Invalid vertex\n");
        return;
    }
    adjMatrix[source][destination] = 1;
    if (!directed)
        adjMatrix[destination][source] = 1;
}

void displayGraph()
{
    printf("Adjacency Matrix Representation:\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, source, destination, directed;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);
    initGraph();

    do
    {
        printf("\nMenu:\n");
        printf("1. Add Edge\n");
        printf("2. Display Graph\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter source and destination vertices: ");
            scanf("%d %d", &source, &destination);
            printf("Is the graph directed? (1 for yes, 0 for no): ");
            scanf("%d", &directed);
            addEdge(source, destination, directed);
            break;
        case 2:
            displayGraph();
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}
