#include <iostream>
#include <string>
using namespace std;

int main() {
    string txt;
    getline(cin, txt);
    int cu = 0;
    int cl = 0;

    for(int z = 0; z < txt.length(); z++) {
        if(islower(txt[z])) {
            cl = cl + 1;
        } else if(isupper(txt[z])) {
            cu = cu + 1;
        }
    }

    if(cu > cl) {
        for(int z = 0; z < txt.length(); z++) {
            txt[z] = toupper(txt[z]);
        }
    } else {
        for(int z = 0; z < txt.length(); z++) {
            txt[z] = tolower(txt[z]);
        }
    }

    cout<<txt;

    return 0;
} // End of Code
