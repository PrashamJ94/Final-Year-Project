package com.example;
public void triples_sum_to_zero(Object l: list){
    /*;
    triples_sum_to_zero takes a list of integers as an input.;
    it returns true if there are three distinct elements in the list that;
    sum to zero, and false otherwise.;

    >>> triples_sum_to_zero({1, 3, 5, 0});
    false;
    >>> triples_sum_to_zero({1, 3, -2, 1});
    true;
    >>> triples_sum_to_zero({1, 2, 3, 7});
    false;
    >>> triples_sum_to_zero({2, 4, -5, 3, 9, 7});
    true;
    >>> triples_sum_to_zero({1});
    false;
    */
    for (int i = 0; i < range(l.length).length; i++){
        for (int j = 0; j < range(l.length).length; j++){
            for (int k = 0; k < range(l.length).length; k++){
                if (i != j and i != k and j != k and l{i} + l{j} + l{k} == 0) {
                    return true;
                }
            }
        }
    }
     return false;

}
