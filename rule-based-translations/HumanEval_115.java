package com.example;
public void max_fill(Object grid, capacity){
    import math;
    /*;
    You are given a rectangular grid of wells. Each row represents a single well,;
    and each 1 in a row represents a single unit of water.;
    Each well has a corresponding bucket that can be used to extract water from it,; 
    and all buckets have the same capacity.;
    Your task is to use the buckets to empty the wells.;
    Output the number of times you need to lower the buckets.;

    HumanEval_115 1:
        Input: 
            grid : {[0,0,1,0}, {0,1,0,0}, {1,1,1,1}];
            bucket_capacity : 1;
        Output: 6;

    HumanEval_115 2:
        Input: 
            grid : {[0,0,1,1}, {0,0,0,0}, {1,1,1,1}, {0,1,1,1}];
            bucket_capacity : 2;
        Output: 5;
}
    
    HumanEval_115 3:
        Input: 
            grid : {[0,0,0}, {0,0,0}];
            bucket_capacity : 5;
        Output: 0;

    Constraints:
        * all wells have the same length;
        * 1 <= grid.length <= 10^2;
        * 1 <= grid{:,1}.length <= 10^2;
        * grid{i}{j} -> 0 | 1;
        * 1 <= capacity <= 10;
    */

    var ans = 0;    
    for (int l = 0; l < grid.length; l++){
        ans += math.ceil(sum(l) / capacity);
    }
    return ans;

