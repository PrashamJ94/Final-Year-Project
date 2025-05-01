#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<int> str2List(string str) {
    stringstream ss(str);
    string token;
    vector<int> ret;
    while(getline(ss, token, ' ')) {
        ret.push_back(stoi(token));
    }
    return ret;
}

int main() {
    string nStr;
    getline(cin, nStr);
    int n = stoi(nStr);
    string vStr;
    getline(cin, vStr);
    vector<int> vList = str2List(vStr);
    string cStr;
    getline(cin, cStr);
    vector<int> cList = str2List(cStr);
    int max = 0;
    for(int i = 0; i < n; i++) {
        int profit = vList[i] - cList[i];
        if(profit > 0) {
            max += profit;
        }
    }
    cout << max << endl;
    return 0;
}

// //End of Code
