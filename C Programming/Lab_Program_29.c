/*
NAME :- ABHINAV SINGH
BRANCH :- ECE
SECTION :- A
ROLL NUMBER :- 2023ECE096
EXAM ROLL NUMBER :- 23294917096
ENROLLMENT NUMBER :- 23DOECBTEC000096
*/

/*
Write a menu driven program to implement Incidence Matrix of a given
a) undirected graph and 
b)directed graph
*/
#include <stdio.h>
#include <stdlib.h>

int **create_incidence_matrix(int num_vertices, int num_edges, int (*edges)[2], int directed)
{
    int i, j;
    int **incidence_matrix = (int **)malloc(num_vertices * sizeof(int *));
    for (i = 0; i < num_vertices; i++)
    {
        incidence_matrix[i] = (int *)malloc(num_edges * sizeof(int));
    }

    for (i = 0; i < num_vertices; i++)
    {
        for (j = 0; j < num_edges; j++)
        {
            incidence_matrix[i][j] = 0;
        }
    }

    for (i = 0; i < num_edges; i++)
    {
        int start_vertex = edges[i][0];
        int end_vertex = edges[i][1];
        incidence_matrix[start_vertex][i] = 1;
        if (!directed)
        {
            incidence_matrix[end_vertex][i] = 1;
        }
        else
        {
            incidence_matrix[end_vertex][i] = -1;
        }
    }

    return incidence_matrix;
}

void print_matrix(int **matrix, int num_vertices, int num_edges)
{
    int i, j;
    for (i = 0; i < num_vertices; i++)
    {
        for (j = 0; j < num_edges; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, num_vertices, num_edges, i;
    printf("Choose the type of graph:\n");
    printf("1. Undirected Graph\n");
    printf("2. Directed Graph\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2)
    {
        printf("Invalid choice. Exiting.\n");
        return 1;
    }

    int directed = (choice == 2) ? 1 : 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    int edges[num_edges][2];
    printf("Enter the edges (format: start_vertex end_vertex):\n");
    for (i = 0; i < num_edges; i++)
    {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    printf("\nIncidence Matrix:\n");
    int **incidence_matrix = create_incidence_matrix(num_vertices, num_edges, edges, directed);
    print_matrix(incidence_matrix, num_vertices, num_edges);

    for (i = 0; i < num_vertices; i++)
    {
        free(incidence_matrix[i]);
    }
    free(incidence_matrix);

    return 0;
}
