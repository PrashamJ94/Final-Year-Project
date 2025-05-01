#include<iostream>
#include<algorithm>
#include<vector>

bool compare(int a, int b)
{
    return (b < a);
}

int main()
{
    std::vector<int> array(10);
    for(int i = 0; i != 10; i++)
        std::cin >> array[i];
    std::sort(array.begin(), array.end(), compare);
    for(int i = 0; i != 3; i++)
        std::cout << array[i] << std::endl;
    return 0;
}
// 
