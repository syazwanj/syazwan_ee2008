#include <stdio.h> /* Include header file for printf */
#define maxV 100 /* Define a constant */

int a[maxV][maxV], visit[maxV];/* Declare a two dimensional array */
int count = 0; /* Declare and initialize variable */
int V, E, x, y;

void read_graph(void); /* Function prototype */
void print_graph(void);
int dfs(int *adj_matr);
int dfs_recurs(int v);

// store 2d array for convenience. Just use this
int arr_2d[7][7] = {
    {0,1,1,0,0,0,0},
    {1,0,1,0,0,0,0},
    {1,1,0,1,0,0,0},
    {0,0,1,0,0,0,0},
    {0,0,0,0,0,1,1},
    {0,0,0,0,1,0,1},
    {0,0,0,0,1,1,0}
};

void main(){
    //read_graph(); /* call function to input graph adjacency matrix */
    //print_graph(); /* call function to output graph adjacency matrix */
    dfs(*arr_2d);
}

void read_graph(void){
    int edge, x;
    printf("\nInput number of vertices: ");
    scanf("%d", &V);
    if (V > maxV){
        printf("Maximum number of vertices exceeded!\n");
    }
    else{
        for (x = 1; x <= V; x++){
            for (y = 1; y <= V; y++){
                a[x][y] = 0;
            }
        }
        for (x = 1; x <= V; x++){
            for (y = 1; y <= V; y++){
                printf("a[%d][%d] = ", x, y);
                scanf("%d", &edge);
                fflush(stdin);
                a[x][y] = edge;
                a[y][x] = edge;
            }
        }
    }
}

void print_graph(void){
    int x, y;
    printf("%d %d %d", x,y,V);
    for (x = 1; x <= V; x++){
        for (y = 1; y <= V; y++){
            printf("a[%d][%d] = %d\n", x, y, a[x][y]);
        }
    }
}

int dfs(int *adj_matr){
    int component;
    count = 0;
    
    for (int i = 1; i <= V; i++){
        visit[i] = 0;
    }

    for (int vertex = 1; vertex <= V; vertex++){
        if (!visit[vertex]){
            component++;
            dfs_recurs(vertex);
        }
    }

    for (int i = 1; i <= V; i++){
        printf("%d", visit[i]);
    }

    return 0;
}

int dfs_recurs(int vertex){
    int y;
    count++;
    visit[vertex] = count;
    for (y = 1; y <= V; y++){
        int w = arr_2d[vertex][y];
        if (!visit[w]){
            dfs_recurs(w);
        }
    }

    return 0;
}