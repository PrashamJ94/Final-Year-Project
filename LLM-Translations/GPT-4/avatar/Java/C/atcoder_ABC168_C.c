#include <stdio.h>
#include <math.h>

int main() {
    int A, B, H, M;
    double AA, BB, HH, MM;
    double ans2;
    double kaku;
    double mkaku;
    double hkaku;
    double AA2;
    double BB2;
    double CC;
    double DD;
    double dkaku;
    double dans2;

    scanf("%d %d %d %d", &A, &B, &H, &M);

    AA = (double)A;
    BB = (double)B;
    HH = (double)H;
    MM = (double)M;

    mkaku = MM * 6;
    hkaku = HH * 30;
    hkaku = hkaku + ((double)M / 2);

    kaku = mkaku - hkaku;
    dkaku = fabs(atan2(sin(kaku * M_PI / 180), cos(kaku * M_PI / 180))) * 180 / M_PI;

    AA2 = AA * AA;
    BB2 = BB * BB;
    CC = AA2 + BB2;
    DD = cos(dkaku * M_PI / 180);
    DD = DD * 2;
    DD = DD * AA;
    DD = DD * BB;

    ans2 = CC - DD;
    dans2 = ans2;
    double ans = sqrt(dans2);

    printf("%.10f\n", ans);

    return 0;
}
// //End of Code
