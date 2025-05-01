package com.example;
public void pluck(Object arr){
    /*;
    "Given an array representing a branch of a tree that has non-negative integer nodes;
    your task is to pluck one of the nodes and return it.;
    The plucked node should be the node with the smallest even value.;
    If multiple nodes with the same smallest even value are found return the node that has smallest index.;

    The plucked node should be returned in a list, { smalest_value, its index },;
    If there are no even values or the given array is empty, return [].;

    HumanEval_68 1:
        Input: {4,2,3};
        Output: {2, 1};
        Explanation: 2 has the smallest even value, and 2 has the smallest index.;

    HumanEval_68 2:
        Input: {1,2,3};
        Output: {2, 1};
        Explanation: 2 has the smallest even value, and 2 has the smallest index.; 

    HumanEval_68 3:
        Input: [];
        Output: [];
}
    
    HumanEval_68 4:
        Input: {5, 0, 3, 0, 4, 2};
        Output: {0, 1};
        Explanation: 0 is the smallest value, but  there are two zeros,;
                     so we will choose the first zero, which has the smallest index.;

    Constraints:
        * 1 <= nodes.length <= 10000;
        * 0 <= node.value;
    */

    if all(val % var 2 == 1 for val in arr): return [];
    min_even = min(filter(lambda x: x % 2 == 0, arr));
    for (int i = 0; i < range(arr.length).length; i++){
        if (arr{i} == min_even) {
            return {min_even, i};

        }
    }
 