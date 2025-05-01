#include<stdio.h>

int main() {
    int n, L, R, QL, QR;
    scanf("%d%d%d%d%d", &n, &L, &R, &QL, &QR);
    int W[n], sum_el[n + 1], i;
    for(i = 0; i < n; i++) {
        scanf("%d", &W[i]);
    }
    sum_el[0] = 0;
    for(i = 1; i < n + 1; i++) {
        sum_el[i] = W[i - 1] + sum_el[i - 1];
    }
    int answer = QR * (n - 1) + sum_el[n] * R;
    for(i = 1; i < n + 1; i++) {
        int energy = L * sum_el[i] + R * (sum_el[n] - sum_el[i]);
        if(i > (n - i)) {
            energy = energy + (i - (n - i) - 1) * QL;
        } else if((n - i) > i) {
            energy = energy + ((n - i) - i - 1) * QR;
        }
        if(energy < answer) {
            answer = energy;
        }
    }
    printf("%d", answer);
    return 0;
} // End of Code
