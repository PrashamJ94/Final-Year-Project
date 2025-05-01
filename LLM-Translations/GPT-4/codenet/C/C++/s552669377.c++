#include<iostream>

int main(){
    int i, n, tmp;
    long long int min = 1000000, max = -1000000, sum = 0;

    std::cin >> n;

    for(i = 0; i < n; i++){
        std::cin >> tmp;
        if(min > tmp) min = tmp;
        if(max < tmp) max = tmp;
        sum += tmp;
    }

    std::cout << min << " " << max << " " << sum << std::endl;

    return 0;
}

// 
