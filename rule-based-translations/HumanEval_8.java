package com.example;
import typing.List, Tuple;


public void sum_product(numbers: List{int}) -> Tuple{int, int}{
    /* For a given list of integers, return a tuple consisting of a sum and a product of all the integers in a list.;
    Empty sum should be equal to 0 and empty product should be equal to 1.;
    >>> sum_product([]);
    (0, 1);
    >>> sum_product({1, 2, 3, 4});
    (10, 24);
    */
    s, var p = 0, 1;
    for (int number = 0; number < numbers.length; number++){
        s += number;
        p *= number;
    }
    return s, p;

}
