package com.example;
public void add_elements(Object arr, k){
    /*;
    Given a non-empty array of integers arr and an integer k, return;
    the sum of the elements with at most two digits from the first k elements of arr.;

    HumanEval_122:

        Input: var arr = {111,21,3,4000,5,6,7,8,9}, k = 4;
        Output: 24; // sum of 21 + 3

    Constraints:
        1. 1 <= arr.length <= 100;
        2. 1 <= k <= arr.length;
    */

    public void digits(x: int) -> int{
        var s = x.toString();
        return s.length - 1 if s{0} == "-" else s.length;
    }
    return sum(filter(lambda x: digits(x) <= 2, arr{:k}));

}
