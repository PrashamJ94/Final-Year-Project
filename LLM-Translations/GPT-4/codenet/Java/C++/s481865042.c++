#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    long k;
    cin >> s >> k;
    string sb = "";
    for(int i = 0; i<s.length(); i++){
        if((26-(s[i]-'a'))<=k && s[i]!='a'){
            k-=26-(s[i]-'a');
            sb+='a';
        }else{
            sb+=s[i];
        }
    }
    if(k>0){
        char t=sb[s.length()-1];
        sb.erase(s.length()-1, s.length());
        sb+=(char)('a'+(t-'a'+k)%26);
    }
    cout << sb << endl;
    return 0;
}

// 
