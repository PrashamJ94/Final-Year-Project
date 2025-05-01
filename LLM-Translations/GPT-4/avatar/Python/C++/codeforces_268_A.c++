
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<string>> q;
    int count = 0;
    for(int i = 0; i < n; i++) {
        string a;
        cin >> a;
        vector<string> temp;
        temp.push_back(a);
        q.push_back(temp);
    }
    for(auto &j : q) {
        for(auto &k : q) {
            if(k == j)
                continue;
            else if(j[0] == k[k.size() - 1])
                count++;
            else
                continue;
        }
    }
    cout << count;
    return 0;
} //End of Code

This C++ code does the same functionality as the Python code. It reads an integer from the standard input, reads the next `n` lines into a vector of vectors, then counts how many times the first character of a string is the same as the last character of another string.
