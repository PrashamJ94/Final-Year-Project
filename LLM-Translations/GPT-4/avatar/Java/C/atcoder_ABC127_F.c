#include <stdio.h>
#include <stdlib.h>

int comp(const void * a, const void * b) {
   return (*(int*)b - *(int*)a);
}

int main() {
    int t, in, i;
    long sumMin = 0, sumMax = 0, sumb = 0;
    int min = 0;
    int pqmin[100000], pqmax[100000];
    int sizeMin = 0, sizeMax = 0;
    
    scanf("%d", &t);
    while (t--) {
        int type;
        scanf("%d", &type);
        if(type == 2) {
            long ans = min;
            ans *= sizeMin;
            ans -= sumMin;
            long ans1 = min;
            ans1 *= sizeMax;
            ans1 = sumMax - ans1;
            printf("%d %ld\n", min, ans + ans1 + sumb);
        } else {
            int b;
            scanf("%d %d", &in, &b);
            sumb += b;
            if (in > min) {
                pqmax[sizeMax++] = in;
                sumMax += in;
            } else {
                pqmin[sizeMin++] = in;
                sumMin += in;
            }
            qsort(pqmin, sizeMin, sizeof(int), comp);
            qsort(pqmax, sizeMax, sizeof(int), comp);
            if (sizeMin > sizeMax) {
                sumMax += pqmin[sizeMin-1];
                sumMin -= pqmin[sizeMin-1];
                pqmax[sizeMax++] = pqmin[--sizeMin];
            }
            if (sizeMin < sizeMax) {
                sumMax -= pqmax[sizeMax-1];
                sumMin += pqmax[sizeMax-1];
                pqmin[sizeMin++] = pqmax[--sizeMax];
            }
            min = pqmin[sizeMin-1];
        }
    }
    return 0;
} // //End of Code.
