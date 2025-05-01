#include <bits/stdc++.h>
using namespace std;

int main () {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> graph(h, vector<int>(w, INT_MAX));
    char temp;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> temp;
            if(temp == '#'){
                graph[i][j] = 0;
            }
        }
    }

    for(int x = 0; x < w-1; x++){
        for(int i = 0; i < h; i++){
            graph[i][x+1] = min(graph[i][x] + 1, graph[i][x+1]);
        }
    }

    for(int x = w-1; x > 0; x--){
        for(int i = 0; i < h; i++){
            graph[i][x-1] = min(graph[i][x] + 1, graph[i][x-1]);
        }
    }

    for(int y = 0; y < h-1; y++){
        for(int i = 0; i < w; i++){
            graph[y+1][i] = min(graph[y][i] + 1, graph[y+1][i]);
        }
    }

    for(int y = h-1; y > 0; y--){
        for(int i = 0; i < w; i++){
            graph[y-1][i] = min(graph[y][i] + 1, graph[y-1][i]);
        }
    }

    int max_value = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            max_value = max(max_value, graph[i][j]);
        }
    }

    cout << max_value << endl;
    return 0;
}

End of Code.
