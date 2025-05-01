#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <sstream>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    int dotIndex = 0;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            dotIndex = i;
            break;
        }
    }

    if (str[dotIndex - 1] == '9') {
        cout << "GOTO Vasilisa." << endl;
    } else if (stoi(str.substr(dotIndex + 1, 1)) > 4) {
        string _str = str.substr(0, dotIndex);
        stringstream ss;
        ss << stoi(_str) + 1;
        cout << ss.str() << endl;
    } else {
        cout << str.substr(0, dotIndex) << endl;
    }
    
    return 0;
}

// //End of Code.
