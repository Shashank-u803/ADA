#include<stdio.h>
#include<stdlib.h>

int sum = 0;  // To store the total weight of MST
int t[10][2]; // To store the edges of MST

void prims(int cost[10][10], int n) {
    int i, j, u, v;
    int min, source;
    int p[10], d[10], s[10];  // Arrays to store parent, distance, and status
    min = 999;  // Initialize min to a large number (infinity)
    source = 0;  // Starting vertex (vertex 0)

    // Initialize arrays
    for (i = 0; i < n; i++) {
        d[i] = cost[source][i];  // Initialize distance to the source vertex
        s[i] = 0;  // Initially, no vertex is in the MST
        p[i] = source;  // Set the parent of each vertex to the source
    }
    s[source] = 1;  // Mark the source vertex as included in MST
    sum = 0;  // Total weight of the MST
    int k = 0;  // Counter for the number of edges in MST

    // Main loop to find MST
    for (i = 0; i < n - 1; i++) {  // Repeat for n-1 iterations
        min = 999;  // Reset min value for each iteration
        u = -1;  // Reset u (the vertex to be added to the MST)

        // Find the vertex with the minimum distance to the MST
        for (j = 0; j < n; j++) {
            if (s[j] == 0 && d[j] < min) {  // If vertex j is not in MST and has a smaller distance
                min = d[j];
                u = j;  // Select vertex u with the smallest edge
            }
        }

        if (u != -1) {
            // Add edge (u, p[u]) to MST
            t[k][0] = u;  // Store the edge
            t[k][1] = p[u];
            k++;  // Increment edge counter
            sum += cost[u][p[u]];  // Add the edge weight to the total sum
            s[u] = 1;  // Mark u as added to the MST

            // Update distances for adjacent vertices
            for (v = 0; v < n; v++) {
                if (s[v] == 0 && cost[u][v] < d[v]) {  // If v is not in MST and a shorter edge exists
                    d[v] = cost[u][v];  // Update the distance to v
                    p[v] = u;  // Set parent of v as u
                }
            }
        }
    }
}

int** create_graph(int n) {
    int** cost = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) {
        cost[i] = (int*)calloc(n, sizeof(int));
    }
    printf("Enter the Cost matrix values (999 if no direct edge)\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("cost[%d][%d]:", i, j);
            scanf("%d", &cost[i][j]);
        }
    }
    return cost;
}

void print_mst(int n) {
    printf("The edges in the Minimum Spanning Tree are:\n");
    for (int i = 0; i < n - 1; i++) {
        printf("%d -- %d\n", t[i][0], t[i][1]);
    }
    printf("Total weight of the MST: %d\n", sum);
}

void free_graph(int** cost, int n) {
    for (int i = 0; i < n; i++) {
        free(cost[i]);
    }
    free(cost);
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int** cost = create_graph(n);

    prims(cost, n); 

    print_mst(n); 

    free_graph(cost, n);  
    return 0;
}
