#include <stdio.h> /* Include header file for printf */
#define maxV 100 /* Define a constant */

int a[maxV][maxV], visit[maxV], sequence[maxV], parent[maxV];
int count = 0; /* Declare and initialize variable */
int V, E, x, y, component;

void read_graph(void); /* Function prototype */
void print_graph(void);
void dfs(int vertex);

// store 2d array for convenience. Just use this
int arr_2d[8][8] = {
    {0,0,0,0,0,0,0,0},
    {0,0,1,1,0,0,0,0},
    {0,1,0,1,0,0,0,0},
    {0,1,1,0,1,0,0,1},
    {0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,1,1},
    {0,1,0,0,0,1,0,1},
    {0,0,0,1,0,1,1,0}
};

void main(){
    //read_graph(); /* call function to input graph adjacency matrix */
    //print_graph(); /* call function to output graph adjacency matrix */
    count = 0;
    V = 7;

    // Mark each vertex with 0 (unvisited)
    for (int i = 1; i <= V; i++){
        visit[i] = 0;
    }
    for (int vertex = 1; vertex <= V; vertex++){
        if (!visit[vertex]){
            component++;
            dfs(vertex);
        }
    }
    printf("parent: ");
    for (int idx = 1; idx <= V; idx++){
        printf("%d", parent[idx]);
    }
    printf("\nsequence: ");
    for (int idx = 1; idx <= V; idx++){
        printf("%d", sequence[idx]);
    }

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
    printf("The adjacency matrix is: \n");
    for (x = 1; x <= V; x++){
        for (y = 1; y <= V; y++){
            printf("a[%d][%d] = %d\n", x, y, a[x][y]);
        }
    }
}

void dfs(int vertex){
    int w;
    count++;
    sequence[vertex] = count; // Mark vertex with count
    visit[vertex] = 1; // Mark vertex as visited
    printf("Visited vertex %d. visit[vertex] = %d. sequence[vertex] = %d \n", vertex, visit[vertex], sequence[vertex]);
    for (int i = 1; i <= V; i++){
        w = arr_2d[vertex][i];
        printf("Value of w and i and vertex is %d %d %d\n",w, i, vertex);
        if (w == 1 && !visit[i]){
            printf("imma visit %d", i);
            parent[i] = vertex;
            dfs(i);
        }
    }
}