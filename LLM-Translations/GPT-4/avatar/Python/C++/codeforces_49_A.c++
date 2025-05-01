#include<iostream>
#include<string>

using namespace std;

int main(){

    string a;
    getline(cin, a);
    string vo = "aeiouyAEIOUY";
    for (int i = a.length() - 1; i >= 0; i--){
        if (a[i] == ' ' || a[i] == '?'){
            continue;
        }
        else{
            if (vo.find(a[i]) != string::npos){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
            break;
        }
    }
    return 0;
} // End of Code
