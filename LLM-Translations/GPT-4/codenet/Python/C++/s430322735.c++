#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> lst;
    int pair = 0;
    for (int i = 0; i < n; ++i) {
        std::string st;
        std::cin >> st;
        std::sort(st.begin(), st.end());
        lst.push_back(st);
    }
    std::sort(lst.begin(), lst.end());
    lst.push_back("end");
    std::string pre = "";
    int tmp_cnt = 0;
    int cnt = 0;
    for (const auto& i : lst) {
        if (i == pre) {
            tmp_cnt += 1;
        } else {
            cnt += (tmp_cnt * (tmp_cnt + 1)) / 2;
            tmp_cnt = 0;
        }
        pre = i;
    }
    std::cout << cnt << std::endl;
    return 0;
}
// 
