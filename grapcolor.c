#include <stdio.h>
#include <conio.h>

#define V 10

int graph[V][V];
int colors[V];
int vertices;

int issafe(int v, int c) {
    int i;
    for (i = 0; i < vertices; i++) {
        if (graph[v][i] && colors[i] == c) {
            return 0;
        }
    }
    return 1;
}

int solvegraphcol(int v, int m) {
    int c;
    if (v == vertices) {
        return 1;
    }
    
    for (c = 1; c <= m; c++) {
        if (issafe(v, c)) {
            colors[v] = c;
            if (solvegraphcol(v + 1, m)) {
                return 1;
            }
            colors[v] = 0;
        }
    }
    return 0;
}

void printColors(int m) {
    int i;
    if (!solvegraphcol(0, m)) {
        printf("Solution does not exist.\n");
        return;
    }
    printf("\nColor assignment:\n");
    for (i = 0; i < vertices; i++) {
        printf("Vertex: %d --> Color %d\n", i, colors[i]);
    }
}

int main() {
    int i, j, m;
    clrscr();
    
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    printf("Enter adjacency matrix (0 or 1):\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("Enter number of colors: ");
    scanf("%d", &m);
    
    printColors(m);
    
    getch();
    return 0;
}
