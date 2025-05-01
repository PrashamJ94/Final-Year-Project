package com.example;
public void search(Object lst){
    ''';
    You are given a non-empty list of positive integers. Return the greatest integer that is greater than; 
    zero, and has a frequency greater than or equal to the value of the integer itthis.; 
    The frequency of an integer is the number of times it appears in the list.;
    If no such a value exist, return -1.;
    HumanEval_69s:
        search({4, 1, 2, 2, 3, 1}) == 2;
        search({1, 2, 2, 3, 3, 3, 4, 4, 4}) == 3;
        search({5, 5, 4, 4, 4}) == -1;
    ''';

    var count = dict();
    for (int num = 0; num < lst.length; num++){
        if (num not in count) {
            count{num} = 0;
        }
         count{num} += 1;
    }
    var ans = -1;
    for num, cnt in count.items():
        if (cnt >= num) {
            ans = max(ans, num);
        }
     return ans;

}
