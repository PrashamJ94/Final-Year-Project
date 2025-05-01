
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

int find(const std::string& a, const std::string& b);

int main() {
    std::string S, T;
    std::getline(std::cin, S);
    std::getline(std::cin, T);
    int min = INT_MAX;
    for(int i = 0; i <= S.length() - T.length(); i++){
        min = std::min(min, find(S.substr(i, T.length()), T));
    }
    if(min != INT_MAX){
        std::cout << min << std::endl;
    }else{
        std::cout << T.length() << std::endl;
    }
    return 0;
}

int find(const std::string& a, const std::string& b){
    int calc = 0;
    for(int x = 0; x < a.length(); x++){
        if(a.at(x) != b.at(x)){
            calc++;
        }
    }
    return calc;
}

// 
