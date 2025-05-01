#include<iostream>
#include<vector>
#include<algorithm>

int main(){
    int a, b, c;
    std::cin >> a >> b >> c;
    std::vector<int> ABC = {a, b, c};
    int count = std::count(ABC.begin(), ABC.end(), 5);
    if(count == 2){
        int sum = a + b + c;
        if(sum == 17)
            std::cout << "YES";
        else
            std::cout << "NO";
    }
    else{
        std::cout << "NO";
    }
    return 0;
} //End of Code
