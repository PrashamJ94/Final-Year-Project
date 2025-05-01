
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<float> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] = arr[i] - int(arr[i]);
    }
    sort(arr.begin(), arr.end());
    int o = 2 * n - arr.size();
    float arr_sum = accumulate(arr.begin(), arr.end(), 0.0);
    float res = 2e9;
    for(int i = 0; i <= n; i++){
        if(i + o >= n){
            res = min(res, abs(i - arr_sum));
        }
    }
    printf("%.3f\n", res);
    return 0;
}
//End of Code

Please note that the `bits/stdc++.h` header file is a GCC specific header file and it includes most of the standard library files. It is not part of the C++ standard and not recommended for use in production code due to its heavy compilation time. The `accumulate` function is included in the `numeric` header file, and this is used to calculate the sum of elements in the `arr` array.
