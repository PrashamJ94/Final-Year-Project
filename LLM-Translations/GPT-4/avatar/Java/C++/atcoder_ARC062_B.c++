#include <iostream>
#include <string>

using namespace std;

class TaskD {
public:
    void solve(string S) {
        int score = 0;
        for (int i = 0; i < S.length(); i++) {
            char my = i % 2 == 0 ? 'g' : 'p';
            char his = S.at(i);
            if (my != his) {
                score += my == 'p' ? 1 : -1;
            }
        }
        cout << score << endl;
    }
};

int main() {
    string S;
    cin >> S;
    TaskD task;
    task.solve(S);
    return 0;
} // //End of Code.
