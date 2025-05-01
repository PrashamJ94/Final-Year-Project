
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n+1];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += a[i];

    if(sum % (n * (n + 1) / 2)) {
        printf("NO\n");
        return 0;
    }
    
    int k = sum / (n * (n + 1) / 2);
    a[n] = a[0];
    int sum_mod = 0, sum_div = 0;
    for(int i = 0; i < n; i++) {
        sum_mod += (k - a[i+1] + a[i]) % n;
        sum_div += ((k - a[i+1] + a[i]) / n) >= 0;
    }

    if(sum_mod || sum_div != n)
        printf("NO\n");
    else
        printf("YES\n");

    return 0;
}

// End of Code

//In the above C code, we first read the integer 'n' and then read the list 'a'. We then calculate the sum of all elements in 'a'. We compare the sum with '(n * (n + 1) / 2)', if the sum is not a multiple of this value, we print "NO" and end the program. If the sum is a multiple, we calculate 'k' and add the first element of 'a' to the end of 'a'. We then calculate two sums: 'sum_mod' and 'sum_div'. If either 'sum_mod' is not zero or 'sum_div' is not equal to 'n', we print "NO", else we print "YES".
