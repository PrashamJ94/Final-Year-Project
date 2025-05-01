#include<iostream>
#include<string>
#include<queue>

using namespace std;

struct P{
  string name;
  int t;
};

int main(){
  int elaps = 0, c;
  int n, q;
  P u;
  queue<P> Q;

  cin >> n >> q;

  for(int i = 0 ; i < n ; i++){
    cin >> u.name >> u.t;
    Q.push(u);
  }

  while(!Q.empty()){
    u = Q.front(); Q.pop();
    c = min(q,u.t);
    u.t -= c;
    elaps += c;
    if(u.t > 0) Q.push(u);
    else{
      cout << u.name << " " << elaps << endl;
    }
  }

  return 0;
}

// 
