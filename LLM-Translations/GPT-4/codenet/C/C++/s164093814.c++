#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

#define M 1046527
#define L 14

unordered_map<long long, string> H;

int getChar(char ch){
  if ( ch == 'A') return 1;
  else if ( ch == 'C') return 2;
  else if ( ch == 'G') return 3;
  else if ( ch == 'T') return 4;
  return 0;
}

long long getKey(string str){
  long long sum = 0, p = 1;
  for (int i = 0; i < str.size(); i++ ){
    sum += p*(getChar(str[i]));
    p *= 5;
  }
  return sum;
}

bool find(string str){
  long long key = getKey(str);
  return H.find(key) != H.end() && H[key] == str;
}

void insert(string str){
  long long key = getKey(str);
  H[key] = str;
}

int main(){
  int n;
  string str, com;
  cin >> n;

  for (int i = 0; i < n; i++ ){
    cin >> com >> str;

    if ( com[0] == 'i' ){
      insert(str);
    } else {
      if (find(str)){
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    }
  }

  return 0;
}

// 
