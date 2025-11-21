#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of vertices

// Stack implementation
int stack[MAX];
int top = -1;

void push(int item) {
    if (top >= MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = item;
}

int pop() {
    if (top < 0)
        return -1; // Stack underflow
    else
        return stack[top--];
}

// DFS using stack
void dfs(int graph[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    push(start);

    printf("DFS traversal starting from vertex %d: ", start);

    while (top != -1) {
        int node = pop();

        if (!visited[node]) {
            printf("%d ", node);
            visited[node] = 1;
        }

        // Push all unvisited adjacent vertices
        for (int i = n - 1; i >= 0; i--) {
            if (graph[node][i] && !visited[i]) {
                push(i);
            }
        }
    }
    printf("\n");
}

int main() {
    int n, start;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    dfs(graph, n, start);

    return 0;
}
