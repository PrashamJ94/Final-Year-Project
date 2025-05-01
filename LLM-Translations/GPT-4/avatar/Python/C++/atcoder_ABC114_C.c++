#include<bits/stdc++.h>
using namespace std;

int N;
int aaa(string n) {
    if(stoi(n) > N)
        return 0;
    set<char> s(n.begin(), n.end());
    int ans = (s.size() == 3 && s.count('7') && s.count('5') && s.count('3')) ? 1 : 0;
    for(char i : "753") {
        ans += aaa(n + i);
    }
    return ans;
}

int main() {
    cin >> N;
    cout << aaa("0") << "\n";
    return 0;
}

// End of Code.
