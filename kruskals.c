#include <stdio.h>

#define MAX_EDGES 100
#define MAX_VERTICES 100

// Using typedef
typedef struct {
    int weight;
    int u;
    int v;
} Edge;

// Find with path compression
int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

// Union by rank
void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

// Manual Bubble Sort
void sortEdges(Edge edges[], int E) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// Kruskal Algorithm
void kruskal(int V, Edge edges[], int E) {

    int parent[MAX_VERTICES], rank[MAX_VERTICES];
    Edge result[MAX_VERTICES];

    int resultSize = 0;
    int minCost = 0;

    // Initialize parent and rank
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    // Sort edges manually
    sortEdges(edges, E);

    // Process edges
    for (int i = 0; i < E; i++) {

        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        if (find(parent, u) != find(parent, v)) {

            unionSets(parent, rank, u, v);

            result[resultSize++] = edges[i];
            minCost += weight;
        }
    }

    // Print MST
    printf("Edges in MST:\n");
    for (int i = 0; i < resultSize; i++) {
        printf("%d -- %d == %d\n",
               result[i].u,
               result[i].v,
               result[i].weight);
    }

    printf("Minimum Cost = %d\n", minCost);
}

int main() {

    int V = 4;
    int E = 5;

    Edge edges[] = {
        {10, 0, 1},
        {6, 0, 2},
        {15, 1, 3},
        {4, 2, 3},
        {5, 1, 2}
    };

    kruskal(V, edges, E);

    return 0;
}
