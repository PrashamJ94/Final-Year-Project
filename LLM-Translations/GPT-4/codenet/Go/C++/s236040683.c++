#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Node {
public:
    vector<int> to;
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<Node> n(N);
    
    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        from--;
        to--;
        n[from].to.push_back(to);
        n[to].to.push_back(from);
    }

    for (int i = 0; i < N; i++) {
        cout << n[i].to.size() << endl;
    }

    return 0;
}

// 
