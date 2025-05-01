#include<iostream>
#include<cstdlib>
#include<stack>
#include<string>

using namespace std;

int main(){
    int a, b;
    string s;
    stack<int> S;

    while(cin >> s){
        if(s == "+"){
            b = S.top(); S.pop();
            a = S.top(); S.pop();
            S.push(a + b);
        } else if(s == "-") {
            b = S.top(); S.pop();
            a = S.top(); S.pop();
            S.push(a - b);
        } else if(s == "*") {
            b = S.top(); S.pop();
            a = S.top(); S.pop();
            S.push(a * b);
        } else{
            S.push(stoi(s));
        }
    }
    cout << S.top() << endl;
    return 0;
}
// 
