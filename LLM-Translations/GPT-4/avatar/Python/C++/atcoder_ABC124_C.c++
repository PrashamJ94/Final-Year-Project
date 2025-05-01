#include <iostream>
#include <string>
#include <map>

int main() {
    std::string s;
    std::cin >> s;

    std::map<char, int> odd;
    std::map<char, int> even;

    for (int i = 0; i < s.size(); i++) {
        if (i % 2 == 0) 
            even[s[i]]++;
        else 
            odd[s[i]]++;
    }

    int even0Odd1 = s.size() - (even['0'] + odd['1']);
    int even1Odd0 = s.size() - (even['1'] + odd['0']);

    std::cout << std::min(even0Odd1, even1Odd0) << std::endl;

    return 0;
} // End of Code.
