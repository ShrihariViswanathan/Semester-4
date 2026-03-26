#include <stdio.h>
#include <stdlib.h>

// Edge structure
typedef struct {
    int u, v, w;
} Edge;

// Disjoint Set
int parent[100], rank[100];

// Find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Union by rank
void unite(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA == rootB) return;

    if (rank[rootA] < rank[rootB])
        parent[rootA] = rootB;
    else if (rank[rootA] > rank[rootB])
        parent[rootB] = rootA;
    else {
        parent[rootB] = rootA;
        rank[rootA]++;
    }
}

// Sort edges by weight
int cmp(const void *a, const void *b) {
    Edge *e1 = (Edge*)a;
    Edge *e2 = (Edge*)b;
    if (e1->w < e2->w) return -1;
    if (e1->w > e2->w) return 1;
    return 0;
}

int main() {
    int V, E;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    Edge edges[E];

    printf("Enter all edges in the format: u v weight\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    // Initialize DSU
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    // Sort edges by weight
    qsort(edges, E, sizeof(Edge), cmp);

    int total = 0, count = 0;

    printf("\nEdges in the MST:\n");
    for (int i = 0; i < E && count < V - 1; i++) {
        if (find(edges[i].u) != find(edges[i].v)) {
            unite(edges[i].u, edges[i].v);
            printf("%d - %d : %d\n", edges[i].u, edges[i].v, edges[i].w);
            total += edges[i].w;
            count++;
        }
    }

    printf("Total weight = %d\n", total);
    return 0;
}
