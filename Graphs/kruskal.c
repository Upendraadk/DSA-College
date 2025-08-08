#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int V, E;
    struct Edge* edge;
};

// Create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// Structure for Union-Find
struct Subset {
    int parent;
    int rank;
};

// Find function with path compression
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union by rank
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare function for sorting edges by weight
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Kruskal's MST Algorithm
void KruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V]; // Store MST edges
    int e = 0; // Count of MST edges
    int i = 0; // Index for sorted edges

    // Step 1: Sort all edges in non-decreasing order of weight
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compareEdges);

    // Allocate memory for subsets for Union-Find
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Process edges
    while (e < V - 1 && i < graph->E) {
        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If it doesn't form a cycle, include it in result
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    // Print the result
    printf("Edges in MST:\n");
    int total_cost = 0;
    for (i = 0; i < e; i++) {
        printf("%d -- %d  weight: %d\n", result[i].src, result[i].dest, result[i].weight);
        total_cost += result[i].weight;
    }
    printf("Total cost of MST: %d\n", total_cost);

    free(subsets);
}

// -------- Main Function --------
int main() {
    int V = 6; // Number of vertices
    int E = 8; // Number of edges
    struct Graph* graph = createGraph(V, E);

    // Add edges: (u, v, weight)
    graph->edge[0] = (struct Edge){0, 1, 4};
    graph->edge[1] = (struct Edge){0, 2, 4};
    graph->edge[2] = (struct Edge){1, 2, 2};
    graph->edge[3] = (struct Edge){1, 3, 6};
    graph->edge[4] = (struct Edge){2, 4, 8};
    graph->edge[5] = (struct Edge){3, 4, 9};
    graph->edge[6] = (struct Edge){3, 5, 10};
    graph->edge[7] = (struct Edge){4, 5, 11};

    KruskalMST(graph);

    free(graph->edge);
    free(graph);
    return 0;
}
