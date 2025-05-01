
#include <stdio.h>
#include <stdlib.h>

#define INF 99999
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

int main() {
    int h, w, x, y;
    scanf("%d %d", &h, &w);
    int **graph = (int **)malloc(h * sizeof(int *));
    for (int i=0; i<h; i++)
         graph[i] = (int *)malloc(w * sizeof(int));
    char temp;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            scanf(" %c", &temp);
            if(temp == '#'){
                graph[i][j] = 0;
            } else {
                graph[i][j] = INF;
            }
        }
    }
    for(x = 0; x < w - 1; x++){
        for(y = 0; y < h; y++){
            graph[y][x+1] = min(graph[y][x] + 1, graph[y][x+1]);
        }
    }
    for(x = w - 1; x > 0; x--){
        for(y = 0; y < h; y++){
            graph[y][x-1] = min(graph[y][x] + 1, graph[y][x-1]);
        }
    }
    for(y = 0; y < h - 1; y++){
        for(x = 0; x < w; x++){
            graph[y+1][x] = min(graph[y][x] + 1, graph[y+1][x]);
        }
    }
    for(y = h - 1; y > 0; y--){
        for(x = 0; x < w; x++){
            graph[y-1][x] = min(graph[y][x] + 1, graph[y-1][x]);
        }
    }
    int max_val = -1;
    for(y = 0; y < h; y++){
        for(x = 0; x < w; x++){
            max_val = max(max_val, graph[y][x]);
        }
    }
    printf("%d\n", max_val);
    return 0;
}

/* End of Code */
