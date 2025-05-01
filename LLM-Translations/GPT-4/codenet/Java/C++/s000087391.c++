#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main() {
    vector<int> result;
    string line;

    while (true) {
        getline(cin, line);
        int n = stoi(line);

        if (n == 0) {
            break;
        }

        vector<int> input(n);
        int sum = 0;

        getline(cin, line);
        stringstream ss(line);
        for (int i = 0; i < n; i++) {
            ss >> input[i];
            sum += input[i];
        }

        double avg = static_cast<double>(sum) / static_cast<double>(n);
        int num = 0;
        for (int i = 0; i < n; i++) {
            if (input[i] <= avg) {
                num++;
            }
        }
        result.push_back(num);
    }

    for (size_t i = 0; i < result.size(); i++) {
        if (result[i] == -1) {
            cout << "NONE" << endl;
        }
        else {
            cout << result[i] << endl;
        }
    }

    return 0;
}

// 
