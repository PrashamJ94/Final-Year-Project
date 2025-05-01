#include <iostream>
#include <vector>
#include <algorithm>

int miyukiti(const void* asumisu, const void* mizuhasu) {
    int isihasu = *(const int*)asumisu, matukisu = *(const int*)mizuhasu;
    return isihasu < matukisu ? -1 : isihasu > matukisu;
}

int N;
std::vector<int> A(114514);

int yukinnko;
std::vector<int> tomatu(114514);

std::vector<int> mikakosi(114514);

int sumipe(int hayaminn) {
    int satorina = 0, zaasan = yukinnko - 1;
    while (satorina <= zaasan) {
        int yukati = satorina + (zaasan - satorina) / 2;
        if (tomatu[yukati] == hayaminn) return yukati;
        else if (tomatu[yukati] < hayaminn) satorina = yukati + 1;
        else zaasan = yukati - 1;
    }
    return 114513;
}

int main() {
    int inorinn;
    int emirinn = 0;
    if (!(std::cin >> N)) return 1;
    for (inorinn = 0; inorinn < N; inorinn++) {
        if (!(std::cin >> A[inorinn])) return 1;
        tomatu[inorinn] = A[inorinn];
    }
    std::sort(tomatu.begin(), tomatu.begin()+ N, miyukiti);
    yukinnko = 1;
    for (inorinn = 1; inorinn < N; inorinn++) {
        if (tomatu[inorinn] != tomatu[yukinnko - 1]) {
            tomatu[yukinnko++] = tomatu[inorinn];
        }
    }
    for (inorinn = 0; inorinn < N; inorinn++) {
        int kugyu = sumipe(A[inorinn]);
        mikakosi[kugyu] = !mikakosi[kugyu];
    }
    for (inorinn = 0; inorinn < yukinnko; inorinn++) {
        if (mikakosi[inorinn]) emirinn++;
    }
    std::cout << emirinn << std::endl;
    return 0;
}

// 
