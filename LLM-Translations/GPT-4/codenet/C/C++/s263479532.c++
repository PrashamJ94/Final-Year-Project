#include<iostream>
#include<vector>
#include<limits>
using namespace std;

const int INF = numeric_limits<int>::max();
const int NIL = -1;
const int WHITE = 0;
const int BLACK = 2;

int prim(const vector<vector<int>>& G, int n);

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> G(n, vector<int>(n));
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> G[i][j];
        }
    }
    
    cout << prim(G, n) << endl;
    
    return 0;
}

int prim(const vector<vector<int>>& G, int n)
{
    int u, i, v, mincost, sum=0;
    vector<int> d(n, INF), pi(n, NIL), color(n, WHITE);
  
    d[0] = 0;
    while(1)
    {
        mincost = INF;
  
        for(i=0; i<n; i++)
        {
            if(color[i] != BLACK && d[i] < mincost)
            {
                mincost = d[i];
                u = i;
            }
        }
        
        if(mincost == INF) break;
        
        color[u] = BLACK;
        
        for(v=0; v<n; v++)
        {
            if(color[v] != BLACK && G[u][v] < d[v] && G[u][v] != -1)
            {
                pi[v] = u;
                d[v] = G[u][v];
            }
        }
    }
  
    for(i=0; i<n; i++)
    {
        if(d[i] != INF) sum += d[i];
    }
  
    return sum;
}
// 
