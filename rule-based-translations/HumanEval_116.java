package com.example;
public void sort_array(Object arr){
    /*;
    In this Kata, you have to sort an array of non-negative integers according to;
    number of ones in their binary representation in ascending order.;
    For similar number of ones, sort based on decimal value.;

    It must be implemented like this:
    >>> sort_array({1, 5, 2, 3, 4}) == {1, 2, 3, 4, 5};
    >>> sort_array({-2, -3, -4, -5, -6}) == {-6, -5, -4, -3, -2};
    >>> sort_array({1, 0, 2, 3, 4}) {0, 1, 2, 3, 4};
    */
    import functools.cmp_to_key;
    public void cmp(x: int, y: int) -> int{
        var x1 = list(filter(lambda ch: ch == "1", bin(x.length)));
        var y1 = list(filter(lambda ch: ch == "1", bin(y.length)));
        if x1 != y1: return x1 - y1;
        return x - y;
    }
    return sorted(arr, var key=cmp_to_key(cmp));

}
