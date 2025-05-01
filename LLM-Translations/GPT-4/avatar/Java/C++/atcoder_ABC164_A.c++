#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    istringstream iss(input);
    vector<string> scList;

    while (iss) {
        string sub;
        iss >> sub;
        scList.push_back(sub);
    }

    int Sheep = stoi(scList[0]);
    int Wolve = stoi(scList[1]);

    if (Wolve >= Sheep) {
        cout << "unsafe" << endl;
    } else {
        cout << "safe" << endl;
    }

    return 0;

} // //End of Code
