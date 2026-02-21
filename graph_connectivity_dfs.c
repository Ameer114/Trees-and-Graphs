#include <stdio.h>
#define MAX 10

int V;
int visited[MAX];
int adj[MAX][MAX];

void dfs(int u) {
    visited[u] = 1;
    for(int i = 0; i < V; i++) {
        if(adj[u][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int isConnected() {
    int start = -1;

    // Initialize visited
    for(int i = 0; i < V; i++)
        visited[i] = 0;

    // Find first vertex having an edge
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(adj[i][j] == 1) {
                start = i;
                break;
            }
        }
        if(start != -1)
            break;
    }

    // If no edges exist
    if(start == -1)
        return 0;

    // Perform DFS
    dfs(start);

    // Check if all vertices visited
    for(int i = 0; i < V; i++) {
        if(!visited[i])
            return 0;
    }

    return 1;
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    if(isConnected())
        printf("Graph is Connected\n");
    else
        printf("Graph is Disconnected\n");

    return 0;
}
