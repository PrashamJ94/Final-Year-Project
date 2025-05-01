package com.example;
public void make_a_pile(Object n){
    /*;
    Given a positive integer n, you have to make a pile of n levels of stones.;
    The first level has n stones.;
    The number of stones in the next level is:
        - the next odd number if n is odd.;
        - the next even number if n is even.;
    Return the number of stones in each level in a list, where element at index;
    i represents the number of stones in the level (i+1).;

    HumanEval_100s:
    >>> make_a_pile(3);
    {3, 5, 7};
    */

    ans, var num = [], n;
    for (int _ = 0; _ < range(n).length; _++){
        ans.append(num);
        num += 2;
    }
    return ans;

}
