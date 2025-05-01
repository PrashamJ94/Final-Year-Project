#include <stdio.h>
#include<stdlib.h>

int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int findGCD(int arr[], int n){
    int result = arr[0];
    for (int i = 1; i < n; i++){
        result = gcd(arr[i], result);
        if(result == 1){
           return 1;
        }
    }
    return result;
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("%d", findGCD(arr, n));
    return 0;
}
// End of Code
