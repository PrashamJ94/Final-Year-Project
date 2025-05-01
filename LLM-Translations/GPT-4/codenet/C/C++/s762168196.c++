#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        sum += a[i];
    }

    int min = a[0];
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }

    std::cout << min << " " << max << " " << sum << std::endl;

    return 0;
}
// 
