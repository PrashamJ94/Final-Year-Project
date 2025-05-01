#include <iostream>
#include <vector>

class calArea{
public:
    int Area(int w, int h ){
        int area = w * h;
        return area;
    }
};

int main() {
    std::vector<int> arr;
    int input;
    
    for(int i = 0; i < 4; i++){
        std::cin >> input;
        arr.push_back(input);
    }
    
    calArea ab;
    int area1 = ab.Area(arr[0], arr[1]);
    int area2 = ab.Area(arr[2], arr[3]);
    
    if(area1 > area2){
        std::cout << area1 << std::endl;
    }else if(area1 < area2){
        std::cout << area2 << std::endl;
    }else if(area1 == area2){
        std::cout << area1 << std::endl;
    }   
    
    return 0;
}
// 
