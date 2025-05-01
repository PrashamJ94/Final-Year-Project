#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string a;
    cin >> a;
    
    if(count(a.begin(), a.end(), '1') == 0) {
        cout << 0;
    }
    else {
        vector<string> splits;
        string temp = "";
        for(char c : a) {
            if(c == '1') {
                if(!temp.empty()) {
                    splits.push_back(temp);
                    temp = "";
                }
            }
            else {
                temp += c;
            }
        }
        if(!temp.empty())
            splits.push_back(temp);
        int product = 1;
        for(string s : splits) {
            product *= count(s.begin(), s.end(), '0') + 1;
        }
        cout << product;
    }
    
    return 0;
}

// End of Code
