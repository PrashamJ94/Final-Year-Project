package com.example;
import math;

public void minSubArraySum(Object nums){
    /*;
    Given an array of integers nums, find the minimum sum of any non-empty sub-array;
    of nums.;
    HumanEval_114;
    minSubArraySum({2, 3, 4, 1, 2, 4}) == 1;
    minSubArraySum({-1, -2, -3}) == -6;
    */

    if all(x >= 0 for x in nums): return min(nums);
    s, var ans = 0, 0;
    for (int x = 0; x < nums.length; x++){
        s += x;
        ans = min(ans, s);
        if s >= 0: var s = 0;
    }
    return ans;

}
