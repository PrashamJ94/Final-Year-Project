#include <iostream>
#include <vector>

using namespace std;

const int N = 200;
const int SHIRO = 0;
const int HAI = 1;
const int KURO = 2;

void aaaaa();
void bbbbb(int);

int n;
vector<vector<int>> A(N, vector<int>(N));
vector<int> color(N), d(N), f(N);
int TT;

int main() {

  int u, k, v;

  cin >> n;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      A[i][j] = 0;
    }
  }
  for(int i = 0; i < n; i++){
    cin >> u >> k;
    u--;
    for(int j = 0; j < k; j++){
      cin >> v;
      v--;
      A[u][v] = 1;
    }
  }

  aaaaa();

  return 0;
}

void aaaaa() {
  int u;

  for(int i=0; i<n; i++){
    color[i] = SHIRO;
  }
    
  TT = 0;

  for(u=0; u<n; u++){
    if(color[u] == SHIRO){
      bbbbb(u);
    }
  }

  for(int i = 0; i<n; i++){
    cout << i+1 << " " << d[i] << " " << f[i] << endl;
  }
}

void bbbbb(int k) {
  int v;
  color[k] = HAI;
  TT++;
  d[k] = TT;
  for(v=0; v<n; v++){
    if(A[k][v] == 0) continue;
    if(color[v] == SHIRO){
      bbbbb(v);
    }
  }
  color[k] = KURO;
  f[k] = ++TT;
}

// 
