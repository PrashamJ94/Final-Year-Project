#include<iostream>
#include<string>

int main() {
    std::string a;
    std::cin >> a;
    
    if (a.find('9') != std::string::npos)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    return 0;
}

// 
