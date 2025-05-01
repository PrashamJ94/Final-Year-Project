#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
int main(){
    int pya;
    cin >> pya;
    vector<string> arre;
    string temp;
    while (pya--) {
        cin >> temp;
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        arre.push_back(temp);
    }
    string oString;
    cin >> oString;
    string lowString = oString;
    transform(lowString.begin(), lowString.end(), lowString.begin(), ::tolower);
    char letter1, letter2;
    cin >> letter1;
    letter1 = tolower(letter1);
    letter2 = (letter1 != 'a') ? 'a' : 'b';
    vector<int> valid(oString.size(), 0);
    set<int> setcito;
    for (string x : arre) {
        size_t pos = lowString.find(x);
        while (pos != string::npos) {
            for (int i = pos; i < pos + x.size(); i++)
                setcito.insert(i);
            pos = lowString.find(x, pos + 1);
        }
    }
    for (int i : setcito) {
        char letter = (lowString[i] != letter1) ? letter1 : letter2;
        oString[i] = (islower(oString[i])) ? tolower(letter) : toupper(letter);
    }
    for (char c : oString)
        cout << c;
    cout << endl;
    return 0;
}

// End of Code
