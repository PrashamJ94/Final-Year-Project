
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint> // uint64_t

using namespace std;

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

void get_int4(int &a1, int &a2, int &a3, int &a4) {
  cin >> a1 >> a2 >> a3 >> a4;
}

// <arr[0]> <arr[1]> .. <arr[size-1]>
void fget_array(vector<int64_t> &arr, int size) {
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

#define NUM_MAX 1000
#define NUM2_MAX (NUM_MAX*NUM_MAX)
#define RANK_MAX 3000

bool asc(int64_t a1, int64_t a2) {
    return a1 < a2;
}

bool desc(int64_t a1, int64_t a2) {
    return a1 > a2;
}

#define VAL_MAX (int64_t)(1e+10)
#define SUM_MAX (VAL_MAX*3)

struct range {
    int start;
    int end;
};
int lower_bound(vector<int64_t> &arr, struct range r, int64_t key) {
    int low = r.start;
    int high = r.end;
    while(low + 1 < high) {
        int mid = (low + high) / 2;
        if(arr[mid] < key) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low + 1;
}

int main() {
    int x, y, z, rank;
    get_int4(x, y, z, rank);
    vector<int64_t> xrr(x), yrr(y), zrr(z);
    fget_array(xrr, x);
    fget_array(yrr, y);
    fget_array(zrr, z);
    int64_t min_sum = VAL_MAX+1;
    int64_t max_sum = 0;
    int i, j;
    for(i = 0; i < z; i++) min_sum = min(min_sum, zrr[i]);
    for(i = 0; i < z; i++) max_sum = max(max_sum, zrr[i]);

    vector<int64_t> pair(NUM2_MAX);
    int idx = 0;
    for(i = 0; i < x; i++) {
        for(j = 0; j < y; j++) {
            pair[idx++] = xrr[i] + yrr[j];
        }
    }
    sort(pair.begin(), pair.begin() + idx, asc);
    min_sum += pair[0];
    max_sum += pair[idx-1];

    vector<int> cache(NUM_MAX);
    vector<int> cnt_map(NUM_MAX);
    vector<int64_t> ans(RANK_MAX);
    int size = x*y*z;
    int64_t prev = min_sum;
    int r;
    for(r = rank; r >= 1; r--) {
        int64_t low = prev-1;
        int64_t high = max_sum+1;
        while(low + 1 < high) {
            int64_t mid = (low + high)/2;
            int cnt = 0;
            for(i = 0; i < z; i++) {
                int64_t pivot = zrr[i];
                struct range r = {cache[i]-1, idx};
                int tmp = lower_bound(pair, r, mid-pivot);
                cnt_map[i] = tmp;
                cnt += tmp;
            }
            if(cnt <= size-r) {
                copy(cnt_map.begin(), cnt_map.end(), cache.begin());
                low = mid;
            } else {
                high = mid;
            }
        }
        ans[r-1] = low;
        if(low == max_sum) break;
        prev = low;
    }
    for(i = 0; i < rank; i++) {
        cout << ((ans[i]==0) ? max_sum : ans[i]) << endl;
    }

    return 0;
}


