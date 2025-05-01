#include<iostream>
#include<string>
using namespace std;
int main() {
    string l, s, p;
    int i;
    cin >> l;
    size_t pos = l.find(".");
    s = l.substr(0, pos);
    p = l.substr(pos+1);
    i = p[0] - '0';
    if (s[s.length() - 1] == '9') {
        cout << "GOTO Vasilisa." << endl;
    } else if (s[s.length() - 1] != '9' && i < 5) {
        cout << s << endl;
    } else {
        int num = stoi(s);
        num += 1;
        cout << num << endl;
    }
    return 0;
} 
// End of Code
