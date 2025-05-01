#include <iostream>
#include <cmath>

int main(){

    // Read input from the user
    int intA;
    std::cin >> intA;

    // Calculate the cube of the input
    double dbAncer = std::pow(intA, 3);
    int intAncer = static_cast<int>(dbAncer);

    // Output the result
    std::cout << intAncer << std::endl;

    return 0;
}
// 
