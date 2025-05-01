#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int A, B, H, M;
    cin >> A >> B >> H >> M;

    double AA = A;
    double BB = B;
    double HH = H;
    double MM = M;

    double ans2;
    double kaku;
    double mkaku;
    double hkaku;
    double AA2;
    double BB2;
    double CC;
    double DD;

    mkaku = MM * 6;
    hkaku = HH * 30 + (double)M / 2;
    kaku = mkaku - hkaku;

    double dkaku = abs(acos(-1) * kaku / 180.0);

    AA2 = AA * AA;
    BB2 = BB * BB;
    CC = AA2 + BB2;
    DD = cos(dkaku) * 2 * AA * BB;

    ans2 = CC - DD;
    double ans = sqrt(ans2);

    cout << fixed << setprecision(15) << ans << endl;

    return 0;
}

// //End of Code.
