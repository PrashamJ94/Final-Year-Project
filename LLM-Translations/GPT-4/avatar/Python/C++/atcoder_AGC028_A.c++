
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b > 0) {
        a = a % b;
        swap(a, b);
    }
    return a;
}

int main() {
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;
    vector<int> Number_i(N), Number_iMN(N), Number_j(M), Kaburi_j, Kaburi_i;
    iota(Number_i.begin(), Number_i.end(), 0);
    transform(Number_i.begin(), Number_i.end(), Number_iMN.begin(), [&](int i) { return i * M / N; });
    iota(Number_j.begin(), Number_j.end(), 0);
    set_intersection(Number_iMN.begin(), Number_iMN.end(), Number_j.begin(), Number_j.end(), back_inserter(Kaburi_j));
    transform(Kaburi_j.begin(), Kaburi_j.end(), back_inserter(Kaburi_i), [&](int j) { return j * N / M; });
    int counter = 0, Flag = 0, Kaburi_Size = Kaburi_i.size();
    while (counter <= Kaburi_Size - 1) {
        if (S[Kaburi_i[counter]] == T[Kaburi_j[counter]]) {
            pass;
        } else {
            Flag = 1;
            break;
        }
        counter += 1;
    }
    if (Flag == 1) {
        cout << -1 << endl;
    } else {
        cout << N * M / gcd(N, M) << endl;
    }
    return 0;
}

// End of Code.
