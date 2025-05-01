#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

class Calculator {
private:
    int k;
    int answer = 0;
    bool isCalculate = false;
    vector<vector<int>> lists;

public:
    Calculator(int n, int k, vector<int>& as) : k(k), lists(n) {
        for (int i = 0; i < n; i++) {
            int j = as[i];
            if (0 < i) {
                lists[j].push_back(i);
            } else if (0 < j) {
                answer++;
            }
        }
    }

    int calculate() {
        if (!isCalculate) {
            dfs(0, 0);
            isCalculate = true;
        }
        return answer;
    }

private:
    int dfs(int a, int pre) {
        int h = 0;
        for (int i : lists[a]) {
            h = max(h, dfs(i, a));
        }
        if (0 < pre && h == k - 1) {
            h = 0;
            answer++;
        } else {
            h++;
        }
        return h;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> as(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
        as[i]--;
    }
    Calculator calc(n, k, as);
    cout << calc.calculate() << endl;
    return 0;
}

// //End of Code
