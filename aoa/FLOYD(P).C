#include <stdio.h>
#include <conio.h>

#define MAX 1000

void floydWarshall(int graph[][10], int n) {
    int dist[10][10], i, j, k;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] != 0)
                dist[i][j] = graph[i][j];
            else if (i != j)
                dist[i][j] = MAX;
            else
                dist[i][j] = 0;
        }
    }

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("Shortest Distance Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i][j] == MAX)
                printf("∞\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[10][10] = {
        {0, 3, 0, 0}, 
        {3, 0, 1, 0},
        {0, 1, 0, 7},  
        {0, 0, 7, 0}  
    };
    int n = 4; 

    floydWarshall(graph, n);

    getch();

    return 0;
}
