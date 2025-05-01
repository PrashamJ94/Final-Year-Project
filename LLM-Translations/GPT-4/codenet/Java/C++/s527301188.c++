#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    stringstream ss(input);

    vector<int> nums;
    string token;
    while (ss >> token) {
        switch (token[0]) {
        case '+':
            nums[nums.size() - 2] = nums[nums.size() - 2] + nums[nums.size() - 1];
            nums.pop_back();
            break;
        case '-':
            nums[nums.size() - 2] = nums[nums.size() - 2] - nums[nums.size() - 1];
            nums.pop_back();
            break;
        case '*':
            nums[nums.size() - 2] = nums[nums.size() - 2] * nums[nums.size() - 1];
            nums.pop_back();
            break;
        default:
            nums.push_back(stoi(token));
            break;
        }
    }
    cout << nums[0] << endl;
    return 0;
}
// 
