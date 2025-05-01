#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<string> S(N);
    for(int i=0; i<N; i++) cin >> S[i];

    string march = "MARCH";
    vector<int> march_lis(5, 0);
    for(string s : S) {
        size_t found = march.find(s[0]);
        if(found != string::npos) march_lis[found]++;
    }

    long long ans = 0;
    for(int i=0; i<5; i++)
        for(int j=i+1; j<5; j++)
            for(int k=j+1; k<5; k++)
                ans += (long long)march_lis[i] * march_lis[j] * march_lis[k];
    
    cout << ans << "\n";

    return 0;
}


This C++ code does the same task as your Python code. It reads the input, counts the occurrence of initial characters in the strings, and then calculates the total combinations of three different characters. It then prints the result.
// End of Code.
