#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
  int n;
  string s;
  cin >> n;
  cin.ignore();
  while(n--){
    getline(cin, s);
    size_t found = s.find("Hoshino");
    while(found != string::npos){
      s[found + 6] = 'a';
      found = s.find("Hoshino", found + 1);
    }
    cout << s << endl;
  }
  return 0;
}
// 
