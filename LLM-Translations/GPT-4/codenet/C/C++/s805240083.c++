#include<iostream>
#include<queue>
#include<string>

#define MAX 100005
#define N 100

using namespace std;

struct P{
  string name;
  int t;
};

queue<P> Q;

void Enqueue(P x){
  if(Q.size()==MAX) return;
  Q.push(x);
}

P Dequeue(void){
  P temp=Q.front();
  Q.pop();
  return temp;
}


int main(){
  int i,q,n,T=0;
  P a;
  cin >> n >> q;

  for (i=0;i<n;i++){
    cin >> a.name >> a.t;
    Enqueue(a);
  }

  while(n!=0){
    a=Dequeue();
    if(a.t>q){
      a.t=a.t-q;
      T+=q;
      Enqueue(a);
    }
    else{
      T=T+a.t;
      cout << a.name << " " << T << endl;
      n--;
    }
  }

  return 0;
}

// 
