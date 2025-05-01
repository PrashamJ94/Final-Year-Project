#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s1, s2, s3;
    std::cin >> s1 >> s2 >> s3;

    s1[0] = toupper(s1[0]);
    s2[0] = toupper(s2[0]);
    s3[0] = toupper(s3[0]);

    std::cout << s1[0] << s2[0] << s3[0] << std::endl;

    return 0;
}

// 
