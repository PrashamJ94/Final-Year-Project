#include<iostream>
using namespace std;

int main(){
    int n, k, x = 0;
    cin >> n >> k;
    if(k <= max(n * n / 2, n * n - (n * n / 2))){
        cout << "YES" << '\n';
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i % 2 == j % 2 && x < k){
                    cout << 'L';
                    x++;
                }
                else 
                    cout << 'S';
            }
            cout << '\n';
        }
    }
    else 
        cout << "NO" << '\n';

    return 0;
} // End of Code.
