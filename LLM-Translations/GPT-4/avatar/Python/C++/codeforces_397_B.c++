#include <iostream>
#include <vector>

using namespace std;

class CodeforcesTask397BSolution {
public:
    int t;
    vector<vector<int>> queries;
    string result;
    void read_input() {
        cin >> t;
        for (int i = 0; i < t; i++) {
            vector<int> query(3);
            cin >> query[0] >> query[1] >> query[2];
            queries.push_back(query);
        }
    }
    void process_task() {
        vector<string> res;
        for (vector<int> query : queries) {
            int k = query[0] / query[1];
            res.push_back((k * query[2] >= query[0]) ? "Yes" : "No");
        }
        for (string s : res) {
            result += s + "\n";
        }
    }
    string get_result() {
        return result;
    }
};

int main() {
    CodeforcesTask397BSolution Solution;
    Solution.read_input();
    Solution.process_task();
    cout << Solution.get_result();
    return 0;
}

// End of Code
