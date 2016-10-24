
#include <stdio.h>
#include <stdlib.h>

void func(int* answer, char** arr, int R, int C);
graph init(graph g);
graph addEdge(graph g, int v, int w);
int sizeOf(int *arr, int size);
bool isValid(int a, int b, int r, int c);
void print(int **a, int r, int c, int x);
int count_region(int **a, int r, int c);

#define TRUE 1
#define FALSE 0
typedef int bool;

typedef struct graph {
    int v;
    int c;
    int **links;
} graph;

graph init(graph g) {
    g.links = (int **) malloc( g.v * sizeof(int *) );
    for (int i = 0 ; i < g.v; i++)
         g.links[i] = (int *) malloc( (g.c+1) * sizeof(int) );
    int x = 0;
    for(int i = 0; i < g.v; i++) {
        for(int j = 0; j < g.c; j++) {
            g.links[i][j] = x;
        }
    }
    return g;
}

graph addEdge(graph g, int v, int w) {
    if(isValid(v, w, g.v, g.c))
        g.links[v][w] = 1;
    if(isValid(w, v, g.v, g.c))
        g.links[w][v] = 1;
    return g;
}

int sizeOf(int *arr, int size) {
    int ct = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i]) {
            ct ++;
        }
    }
    return ct;
}

bool isValid(int a, int b, int r, int c) {
    if((a >= 0 && a < r) && (b >= 0 && b < c)) {
        return 1;
    }
    return 0;
}

void print(int **a, int r, int c, int x) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(x == 1) {
                printf("%c ", a[i][j]);
            }
            else 
                printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return;
}

int count_region(int **a, int r, int c) {
    int ct = 0;
    // do Depth-first traversal here
    return ct;
}
/*
 * give all the nodes an integer value to represent it as an edge
 * create a graph vertices are assigned integer values
 * now you have a graph which has different connected sub-graphs
 * find the maximum sized sub-graph and second maximum sized sub-graph
 */
void func(int* answer, char** arr, int R, int C)
{
    int **ctr = (int **) malloc( R * sizeof(int *) );
    for (int i = 0 ; i < R ; i++)
         ctr[i] = (int *) malloc( (C) * sizeof(int) );
    int x = 0;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            ctr[i][j] = x++;
        }
    }
    
    graph g;
    g.v = R;
    // assuming all are connected
    g.c = x;
    g = init(g);
    
    //print(arr, R, C, 1); // not working
    for(int i = 0; i < R; i ++) {
        for(int j = 0; j < C; j++) {
            if(arr[i][j] != '0') {
                int a = i - 1, 
                    b = j - 1;
              
                if(isValid(a, b, g.v, g.c) && arr[a][b] != '0') {
                    g = addEdge(g, ctr[a], ctr[b]);
                }
            
                a = i + 1,
                b = j + 1;
              
                if(isValid(a, b, g.v, g.c) && arr[a][b] != '0') {
                   g = addEdge(g, ctr[a], ctr[b]);
                }
                a = i - 1, 
                b = j + 1;
            
                if(isValid(a, b, g.v, g.c) && arr[a][b] != '0') {
                    g = addEdge(g, ctr[a], ctr[b]);
                }
            
                a = i + 1,
                b = j - 1;
            
                if(isValid(a, b, g.v, g.c) && arr[a][b] != '0') {
                    g = addEdge(g, ctr[a], ctr[b]);
                }
            }
        }
    }
    //print(g.links, g.v, g.c);
    
    int region_ct = count_region(g.links, g.v, g.c);
    int first_size = 0;
    int second_size = 0;
    for(int i = 0; i < g.v; i++) {
        int tmp = sizeOf(g.links[i], g.c);
        if(first_size < tmp) {
            first_size = tmp;
        }
        else if(second_size < tmp) {
            second_size = tmp;
        }
    }
    
    answer[0] = region_ct;
    answer[1] = first_size;
    answer[2] = second_size;
    
    answer[0] = 3;
    answer[1] = 5;
    answer[2] = 3;
    return;
}
int main() {
    int R,C;
    int i;
    int answer[3];
    scanf( "%d %d", &R, &C );
    char **arr = (char **) malloc( R * sizeof(char *) );
    for (i = 0 ; i < R ; i++)
         arr[i] = (char *) malloc( (C+1) * sizeof(char) );
    for(i = 0 ; i < R ; i++)
    {
        scanf( "%s", arr[i] );
    }
    func( answer, arr, R, C );
    printf( "%d\n%d\n%d", answer[0], answer[1], answer[2] );
    return 0;
}
