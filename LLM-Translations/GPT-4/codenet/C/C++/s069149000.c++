#include<iostream>
#include<vector>
#include<limits>
using namespace std;

const int INF = 100000;
const int MAX = 101;
const int NIL = -6;
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

vector<vector<int>> G(MAX, vector<int>(MAX));
int n;

void prim(){
  int i,j;
  vector<int> d(MAX, INF);
  vector<int> pi(MAX, NIL);
  vector<int> color(MAX, WHITE);
  int min,u,v,sum=0;

  d[0] = 0;

  while(1){
    min = INF;
    u = NIL;
    for(i=0;i<n;i++){
      if(color[i] != BLACK && d[i] < min){
        min = d[i];
        u = i;
      }
    }
    if(u == NIL){
      break;
    }
    color[u] = BLACK;
    for(v=0;v<n;v++){
      if(color[v] != BLACK && G[u][v] != INF){
        if(d[v] > G[u][v]){
          d[v] = G[u][v];
          pi[v] = u;
          color[v] = GRAY;
        }
      }
    }
  }
  for(i=0;i<n;i++){
    if(pi[i] != NIL)sum += G[i][pi[i]];
  }
  cout << sum << endl;
}

int main(){
  int e;
  int i,j;

  cin >> n;

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      cin >> e;
      if(e == -1){
        G[i][j] = INF;
      }else{
        G[i][j] = e;
      }
    }
  }

  prim();
  return 0;
}
//
