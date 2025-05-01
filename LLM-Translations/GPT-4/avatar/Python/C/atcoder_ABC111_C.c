#include <stdio.h>
#define MAX 100002

int main() {
    int n, i, val;
    scanf("%d", &n);
    int x[n], a[n], b[n], cnta[MAX + 1] = {0}, cntb[MAX + 1] = {0};
    for(i = 0; i < n; i++) {
        scanf("%d", &x[i]);
        if(i % 2 == 0) {
            a[i] = x[i];
            cnta[x[i]]++;
        } else {
            b[i] = x[i];
            cntb[x[i]]++;
        }
    }
    int vala = 0, valb = 0, maxCnta = 0, maxCntb = 0, vala1 = 0, valb1 = 0, maxCnta1 = 0, maxCntb1 = 0;
    for(i = 0; i < n; i += 2) {
        if(cnta[a[i]] > maxCnta) {
            maxCnta = cnta[a[i]];
            vala = a[i];
        }
        if(cnta[a[i]] > maxCnta1 && vala != a[i]) {
            maxCnta1 = cnta[a[i]];
            vala1 = a[i];
        }
    }
    for(i = 1; i < n; i += 2) {
        if(cntb[b[i]] > maxCntb) {
            maxCntb = cntb[b[i]];
            valb = b[i];
        }
        if(cntb[b[i]] > maxCntb1 && valb != b[i]) {
            maxCntb1 = cntb[b[i]];
            valb1 = b[i];
        }
    }
    int resa = 0, resb = 0, resa1 = 0, resb1 = 0;
    if(vala != valb) {
        for(i = 0; i < n; i++) {
            if(i % 2 == 0 && a[i] != vala)
                resa++;
            else if(i % 2 != 0 && b[i] != valb)
                resb++;
        }
        printf("%d\n", resa + resb);
    } else {
        for(i = 0; i < n; i++) {
            if(i % 2 == 0) {
                if(a[i] != vala)
                    resa++;
                if(a[i] != vala1)
                    resa1++;
            } else {
                if(b[i] != valb)
                    resb++;
                if(b[i] != valb1)
                    resb1++;
            }
        }
        printf("%d\n", (resa + resb1) < (resa1 + resb) ? (resa + resb1) : (resa1 + resb));
    }
    return 0;
}

// End of Code
