#include <iostream>
#include <vector>
#include <bitset>

int main() {
    int h, w, ka;
    std::cin >> h >> w >> ka;
    std::vector<std::string> mat(h);
    for (int i = 0; i < h; ++i) {
        std::cin >> mat[i];
    }

    int ans = 0;
    for (int i = 0; i < (1 << (h + w)); ++i) {
        std::bitset<32> b(i);
        std::string rs = b.to_string().substr(32 - h, h);
        std::string cs = b.to_string().substr(32 - w, w);
        int ct = 0;
        for (int l = 0; l < h; ++l) {
            for (int k = 0; k < w; ++k) {
                if (mat[l][k] == '#' && rs[l] == '0' && cs[k] == '0') {
                    ct += 1;
                }
            }
        }
        if (ct == ka) {
            ans += 1;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
// 
