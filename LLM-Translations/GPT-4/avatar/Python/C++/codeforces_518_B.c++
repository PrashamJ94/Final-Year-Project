#include<iostream>
#include<map>
#include<cctype>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    map<char, int> freqs, freqt;
    int yay = 0, whoops = 0;

    for(char c : s){
        freqs[c]++;
    }

    for(char c : t){
        freqt[c]++;
    }

    for(auto it = freqs.begin(); it != freqs.end(); it++){
        while(it->second > 0 && freqt[it->first] > 0){
            yay++;
            it->second--;
            freqt[it->first]--;
        }
    }

    for(auto it = freqs.begin(); it != freqs.end(); it++){
        while(it->second > 0){
            if(islower(it->first) && freqt[toupper(it->first)] > 0){
                whoops++;
                it->second--;
                freqt[toupper(it->first)]--;
            }
            else if(isupper(it->first) && freqt[tolower(it->first)] > 0){
                whoops++;
                it->second--;
                freqt[tolower(it->first)]--;
            }
            else{
                break;
            }
        }
    }
    cout << yay << " " << whoops << endl;
    return 0;
} // End of Code

