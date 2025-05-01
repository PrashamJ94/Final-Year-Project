package com.example;
public void is_sorted(Object lst){
    ''';
    Given a list of numbers, return whether or not they are sorted;
    in ascending order. If list has more than 1 duplicate of the same;
    number, return false. Assume no negative numbers and only integers.;

    HumanEval_126s;
    is_sorted({5}) ➞ true;
    is_sorted({1, 2, 3, 4, 5}) ➞ true;
    is_sorted({1, 3, 2, 4, 5}) ➞ false;
    is_sorted({1, 2, 3, 4, 5, 6}) ➞ true;
    is_sorted({1, 2, 3, 4, 5, 6, 7}) ➞ true;
    is_sorted({1, 3, 2, 4, 5, 6, 7}) ➞ false;
    is_sorted({1, 2, 2, 3, 3, 4}) ➞ true;
    is_sorted({1, 2, 2, 2, 3, 4}) ➞ false;
    ''';

    var count = dict();
    for (int x = 0; x < lst.length; x++){
        if x not in count: count{x} = 0;
        count{x} += 1;
        if count{x} > 2: return false;
    }
    return var lst == sorted(lst);

}
