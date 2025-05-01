#include <iostream>
#include <vector>

using namespace std;

int main() {
    int size;
    cin >> size;
    vector<vector<int>> graph(size, vector<int>(size, 0));

    int id = 0;
    int cols = 0;
    vector<int> row(size, 0);
    for (int i = 0; i < size; i++) {
        cin >> id;
        cin >> cols;
        row = vector<int>(size, 0);
        for (int j = 0; j < cols; j++) {
            int col;
            cin >> col;
            row[col - 1] = 1;
        }
        graph[id - 1] = row;
    }

    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j];
            if (j < graph[i].size() - 1)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}
// 
