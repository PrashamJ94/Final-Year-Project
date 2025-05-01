C++
#include <bits/stdc++.h>
using namespace std;

int compare (vector<char>& aa , int i , vector<char>& bb , int j , int m ) {
    while ( m -- > 0 ) {
        char a = toupper ( aa [ i ] ) ;
        char b = toupper ( bb [ j ] ) ;
        if ( a != b ) return a - b ;
        i ++ ; j ++ ;
    }
    return 0 ;
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> ss(n);
    for (int i = 0 ; i < n ; i ++ ) {
        string temp;
        cin >> temp;
        ss[i] = vector<char>(temp.begin(), temp.end());
    }
    string temp;
    cin >> temp;
    vector<char> cc(temp.begin(), temp.end());
    int m = cc.size();
    char c;
    cin >> c;
    char c_ = toupper(c);
    char a = c == 'a' ? 'b' : 'a';
    char a_ = toupper(a);
    vector<bool> lucky(m, false);
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            int l = ss[i].size();
            if (m - j >= l && compare(cc, j, ss[i], 0, l) == 0)
                for (int h = 0; h < l; h++)
                    lucky[j + h] = true;
        }
    }
    for (int j = 0; j < m; j++) {
        if (lucky[j]) {
            if (tolower(cc[j]) == c)
                cc[j] = isupper(cc[j]) ? a_ : a;
            else
                cc[j] = isupper(cc[j]) ? c_ : c;
        }
    }
    for (char ch: cc) {
        cout << ch;
    }
    cout << "\n";
    return 0;
}

////End of Code
