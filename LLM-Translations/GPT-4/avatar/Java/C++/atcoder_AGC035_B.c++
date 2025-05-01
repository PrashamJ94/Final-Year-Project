#include <bits/stdc++.h>
using namespace std;
vector<int> connect[200010];
int visited[200010];
bool odd[200010];
string print;
void dfs(int crt, int parent) {
    visited[crt]=1;
    for(auto child: connect[crt]) {
        if(child==parent || visited[child]==1) continue;
        else if(visited[child]==2) {
            print+=to_string(crt+1) + " " + to_string(child+1) + "\n";
            odd[crt] = !odd[crt];
        } else {
            dfs(child, crt);
            if(odd[child]) {
                print+=to_string(child+1) + " " + to_string(crt+1) + "\n";
                odd[child] = !odd[child];
            } else {
                print+=to_string(crt+1) + " " + to_string(child+1) + "\n";
                odd[crt] = !odd[crt];
            }
        }
    }
    visited[crt]=2;
}
int main() {
    int numNode,numEdge;
    cin >> numNode >> numEdge;
    for(int i=0; i<numEdge; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        connect[a].push_back(b);
        connect[b].push_back(a);
    }
    if(numEdge%2!=0) {
        cout << -1 << endl;
        return 0;
    }
    dfs(0, -1);
    cout << print;
    return 0;
} 
////End of Code
