
#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
int seen[200005], par[200005], child_num[200005];
deque<int> que, seq;

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N - 1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    que.push_back(1);
    seen[1] = 1;
    while(!que.empty()){
        int v = que.front();
        que.pop_front();
        for(int u : adj[v]){
            if(seen[u] == 0){
                seen[u] = 1;
                par[u] = v;
                child_num[v]++;
                que.push_back(u);
            }
        }
    }
    for(int i = 1; i <= N; i++){
        if(child_num[i] == 0){
            seq.push_back(i);
        }
    }
    while(!seq.empty()){
        int c = seq.back();
        seq.pop_back();
        seen[c] = 0;
        if(seen[par[c]] == 0){
            cout << "First" << endl;
            return 0;
        }
        seen[par[c]] = 0;
        child_num[par[par[c]]]--;
        if(child_num[par[par[c]]] == 0){
            seq.push_back(par[par[c]]);
        }
    }
    cout << "Second" << endl;
    return 0;
}

// End of Code
