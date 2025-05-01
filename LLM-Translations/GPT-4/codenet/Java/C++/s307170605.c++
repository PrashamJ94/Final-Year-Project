#include <iostream>
#include <vector>

using namespace std;

int main() {
    for(int i = 0; i < 5; i++){
        int input;
        cin >> input;
        if(input == 0){
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}
// 
