#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
using namespace boost::multiprecision;

int main() {
    string sa, sb;
    cin >> sa >> sb;
    cpp_dec_float_50 A(sa);
    cpp_dec_float_50 B(sb);
    cpp_dec_float_50 result = A * B;
    cout << fixed << setprecision(0) << result << endl;
    return 0;
}

// 
