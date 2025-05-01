#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v(10);
    int sum = 0;
    
    for (int i = 0; i < 10; i++)
        std::cin >> v[i];
    
    for (int i = 0; i < 10; i++)
        sum += v[i];
    
    std::cout << sum << std::endl;
    
    return 0;
}
// 
