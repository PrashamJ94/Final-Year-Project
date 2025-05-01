package com.example;
public void pairs_sum_to_zero(Object l){
    /*;
    pairs_sum_to_zero takes a list of integers as an input.;
    it returns true if there are two distinct elements in the list that;
    sum to zero, and false otherwise.;
    >>> pairs_sum_to_zero({1, 3, 5, 0});
    false;
    >>> pairs_sum_to_zero({1, 3, -2, 1});
    false;
    >>> pairs_sum_to_zero({1, 2, 3, 7});
    false;
    >>> pairs_sum_to_zero({2, 4, -5, 3, 5, 7});
    true;
    >>> pairs_sum_to_zero({1});
    false;
    */
    for (int i = 0; i < range(l.length).length; i++){
        for (int j = 0; j < range(l.length).length; j++){
            if (i != j and l{i} + l{j} == 0) {
                return true;
            }
        }
    }
     return false;

}
