package com.example;
public void below_threshold(Object l: list, t: int){
    /*Return true if all numbers in the list l are below threshold t.;
    >>> below_threshold({1, 2, 4, 10}, 100);
    true;
    >>> below_threshold({1, 20, 4, 10}, 5);
    false;
    */
    return all(x < t for x in l);

}
