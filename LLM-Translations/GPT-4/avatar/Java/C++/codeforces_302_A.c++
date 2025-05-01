#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    string res = "";
    int o = 0, e = 0;
    for(int i = 0; i < n; i++)
        if(arr[i] == 1) o++;
        else e++;

    for(int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        if((r - l + 1) % 2 == 1) res += "0\n";
        else {
            if((r - l + 1) / 2 <= o && (r - l + 1) / 2 <= e) res += "1\n";
            else res += "0\n";
        }
    }
    cout << res;
    return 0;
}

// //End of Code
